#include "Renderer.h"
#include "engine.h"
#include "vertexData.h"

bool start = true;

double simLength = 0.002;

int p1Score, p2Score;

//motion variables
float rotateSpeed = 0.0f; //rate of change of the rotate - in radians per second
float rotationAcceleration = 3.0f;

float rotateSpeed1 = 0.0f; //rate of change of the rotate - in radians per second
float rotationAcceleration1 = 3.0f;

float rotateSpeedW = 0.0f; //rate of change of the rotate - in radians per second
float rotationAccelerationW = 3.0f;

glm::vec3 translateSpeed = glm::vec3(0.0f, 0.0f, 0.0f);
glm::vec3 translateAcceleration = glm::vec3(4.0f, 4.0f, 4.0f);

glm::vec3 translateSpeed1 = glm::vec3(0.0f, 0.0f, 0.0f);
glm::vec3 translateAcceleration1 = glm::vec3(4.0f, 4.0f, 4.0f);

glm::vec3 translateSpeedW = glm::vec3(0.0f, 0.0f, 0.0f);
glm::vec3 translateAccelerationW = glm::vec3(4.0f, 4.0f, 4.0f);

// camera variables
glm::vec3 eyePoint = glm::vec3(0, 0, 5);
glm::vec3 lookAtPoint = glm::vec3(0, 0, 0);
glm::vec3 upVector = glm::vec3(0, 1, 0);

glm::vec3 eyePointMove = glm::vec3(0, 0, 0);
glm::vec3 eyePointAcceleration = glm::vec3(0.025, 0.025, 0.025);

int mousePosX, mousePosY;
float horizontalAngle = 3.14f;
float verticalAngle = 0.0f;
float speed = 2.0f;
float mouseSpeed = 0.005f;

glm::vec3 rightVar(
	sin(horizontalAngle - 3.14f / 2.0f), 0,
	cos(horizontalAngle - 3.14f / 2.0f));

float random1, random2, random3 = 0.0f;

glm::vec3 modelPosition = glm::vec3(-4.0f, 4.0f, 0.0f);  //where is starts
glm::vec3 modelScale = glm::vec3(1.0f, 1.0f, 1.0f); //what size it starts
float modelRotationZ = 0.0f; // angles in radians around Z

glm::vec3 modelPosition1 = glm::vec3(4.0f, -4.0f, 0.0f);
glm::vec3 modelScale1 = glm::vec3(1.0f, 1.0f, 1.0f);
float modelRotationZ1 = 0.0f; // angles in radians around Z

float cube1left =	-4.25f;
float cube1right =	-3.75f;
float cube1bottom =	 3.75f;
float cube1top =	 4.25f;

float cube2left =	 3.75f;
float cube2right =	 4.25f;
float cube2bottom = -4.25f;
float cube2top =	-3.75f;

float wayX = random1;
float wayY = random2;


Renderer::Renderer()
{
	
}

Renderer::~Renderer()
{
}

void Renderer::runRender()
{	
	
	renderInput();
	updateSim();

	glClearDepth(1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	

	render();
}

std::string LoadShaderFromFile(const std::string& filename)
{
	std::ifstream file;
	std::string source;
	std::string line;

	file.open(filename); // file name passed in

	if (file.is_open()) // open the file
	{
		while (file.good())
		{
			getline(file, line);
			source.append(line + "\n"); // add the \n to the end of each line
		}
	}
	else
	{
		std::cout << "Couldn't open shader: " << filename << std::endl; // bad error handeling
	}

	return source;
}

GLuint createShader(GLenum eShaderType, const std::string &strShaderFile)
{
	GLuint shader = glCreateShader(eShaderType);
	const char *strFileData = strShaderFile.c_str();
	glShaderSource(shader, 1, &strFileData, NULL);

	glCompileShader(shader);

	GLint status;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
	if (status == GL_FALSE)
	{
		GLint infoLogLength;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLength);

		GLchar *strInfoLog = new GLchar[infoLogLength + 1];
		glGetShaderInfoLog(shader, infoLogLength, NULL, strInfoLog);

		const char *strShaderType = NULL;
		switch (eShaderType)
		{
		case GL_VERTEX_SHADER: strShaderType = "vertex"; break;
		case GL_GEOMETRY_SHADER: strShaderType = "geometry"; break;
		case GL_FRAGMENT_SHADER: strShaderType = "fragment"; break;
		}

		fprintf(stderr, "Compile failure in %s shader:\n%s\n", strShaderType, strInfoLog);
		delete[] strInfoLog;
	}

	return shader;
}

GLuint createProgram(const std::vector<GLuint> &shaderList)
{
	GLuint program = glCreateProgram();

	for (size_t iLoop = 0; iLoop < shaderList.size(); iLoop++)
		glAttachShader(program, shaderList[iLoop]);

	glLinkProgram(program);

	GLint status;
	glGetProgramiv(program, GL_LINK_STATUS, &status);
	if (status == GL_FALSE)
	{
		GLint infoLogLength;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &infoLogLength);

		GLchar *strInfoLog = new GLchar[infoLogLength + 1];
		glGetProgramInfoLog(program, infoLogLength, NULL, strInfoLog);
		fprintf(stderr, "Linker failure: %s\n", strInfoLog);
		delete[] strInfoLog;
	}

	for (size_t iLoop = 0; iLoop < shaderList.size(); iLoop++)
		glDetachShader(program, shaderList[iLoop]);

	return program;
}

void Renderer::runShaders()
{
	initializeProgram();
	initializeVertexBuffer();

	glGenVertexArrays(1, &vao); 
	glBindVertexArray(vao);
}

void Renderer::initializeProgram()
{
	std::vector<GLuint> shaderList;

	std::string vertexSource = LoadShaderFromFile("shaders/shader.vert"); // pass in the file path to the string var aand send to load shader from file
	std::string fragmentSource = LoadShaderFromFile("shaders/shader.frag");

	shaderList.push_back(createShader(GL_VERTEX_SHADER, vertexSource));
	shaderList.push_back(createShader(GL_FRAGMENT_SHADER, fragmentSource));

	theProgram = createProgram(shaderList);
	if (theProgram == 0)
	{
		fatalError("GLSL program creation error.");
	}
	

	positionLocation = glGetAttribLocation(theProgram, "position");
	colorLocation = glGetAttribLocation(theProgram, "color");
	modelMatrixLocation = glGetUniformLocation(theProgram, "modelMatrix");
	viewMatrixLocation = glGetUniformLocation(theProgram, "viewMatrix");
	projectionMatrixLocation = glGetUniformLocation(theProgram, "projectionMatrix");

	for_each(shaderList.begin(), shaderList.end(), glDeleteShader);
}

void Renderer::initializeVertexBuffer()
{
	
	glGenBuffers(1, &vertexBufferObject);
		glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
		glBufferData(GL_ARRAY_BUFFER, sizeof(cubeGreen), cubeGreen, GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	

	glGenBuffers(1, &vertexBufferObject1);
		glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject1);
		glBufferData(GL_ARRAY_BUFFER, sizeof(cubeRed), cubeRed, GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &vertexBufferObject2D);
		glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject2D);
		glBufferData(GL_ARRAY_BUFFER, sizeof(_waypointQuad), _waypointQuad, GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

}

void Renderer::render()
{
	glUseProgram(theProgram);

	glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, glm::value_ptr(viewMatrix));
	glUniformMatrix4fv(projectionMatrixLocation, 1, GL_FALSE, glm::value_ptr(projectionMatrix));

	glEnableVertexAttribArray(positionLocation);
	glEnableVertexAttribArray(colorLocation);

	//cube
	size_t colorData = sizeof(cubeGreen) / 2;
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject); 
	glVertexAttribPointer(positionLocation, 4, GL_FLOAT, GL_FALSE, 0, 0); 
	glVertexAttribPointer(colorLocation, 4, GL_FLOAT, GL_FALSE, 0, (void*)colorData); 
	glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, glm::value_ptr(glm::mat4(modelMatrix)));
	glDrawArrays(GL_TRIANGLES, 0, 72);

	//cubeRed
	size_t colorData1 = sizeof(cubeRed) / 2;
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject1);
	glVertexAttribPointer(positionLocation, 4, GL_FLOAT, GL_FALSE, 0, 0);
	glVertexAttribPointer(colorLocation, 4, GL_FLOAT, GL_FALSE, 0, (void*)colorData1);
	glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, glm::value_ptr(glm::mat4(modelMatrix1)));
	glDrawArrays(GL_TRIANGLES, 0, 72);

	size_t colorDataQ = sizeof(_waypointQuad) / 2;
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject2D);
	glVertexAttribPointer(positionLocation, 4, GL_FLOAT, GL_FALSE, 0, 0);
	glVertexAttribPointer(colorLocation, 4, GL_FLOAT, GL_FALSE, 0, (void*)colorDataQ);
	glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, glm::value_ptr(glm::mat4(modelMatrixW)));
	glDrawArrays(GL_TRIANGLES, 0, 6);

	glDisableVertexAttribArray(0); 
	glUseProgram(0);
}


void Renderer::renderInput()
{
	SDL_Event _camEvent;

	while (SDL_PollEvent(&_camEvent)) {
		switch (_camEvent.type)
		{
		
		case SDL_QUIT: _GameState = GameState::EXIT; break;// press the close button to switch game state
			
			//keydown handling - we should to the opposite on key-up for direction controls (generally)
		case SDL_KEYDOWN:

			if (!_camEvent.key.repeat)
				switch (_camEvent.key.keysym.sym)
				{
					case SDLK_ESCAPE: _GameState = GameState::EXIT; break;

					//top tank
					case SDLK_d:		translateSpeed.x += translateAcceleration.x; cube1left += translateAcceleration.x; cube1right += translateAcceleration.x;  break;
					case SDLK_a:		translateSpeed.x -= translateAcceleration.x; cube1left -= translateAcceleration.x; cube1right -= translateAcceleration.x;  break;

					case SDLK_w:		translateSpeed.y += translateAcceleration.y; cube1top += translateAcceleration.y; cube1bottom += translateAcceleration.y; break;
					case SDLK_s:		translateSpeed.y -= translateAcceleration.y; cube1top -= translateAcceleration.y; cube1bottom -= translateAcceleration.y; break;

					//case SDLK_q: rotateSpeed += rotationAcceleration; break;
					//case SDLK_e: rotateSpeed -= rotationAcceleration; break;

					//bottom tank
						
					case SDLK_LEFT:		translateSpeed1.x -= translateAcceleration1.x; cube2left -= translateAcceleration.x; cube2right -= translateAcceleration.x;  break;
					case SDLK_RIGHT:	translateSpeed1.x += translateAcceleration1.x; cube2left += translateAcceleration.x; cube2right += translateAcceleration.x; break;

					case SDLK_UP:		translateSpeed1.y += translateAcceleration1.y; cube2top += translateAcceleration.y; cube2bottom += translateAcceleration.y; break;
					case SDLK_DOWN:		translateSpeed1.y -= translateAcceleration1.y; cube2top -= translateAcceleration.y; cube2bottom -= translateAcceleration.y; break;

					//camera
					case SDLK_KP_5: eyePointMove.z -= eyePointAcceleration.z; break;
					case SDLK_KP_0: eyePointMove.z += eyePointAcceleration.z; break;

					case SDLK_KP_4: eyePointMove.x -= eyePointAcceleration.x; break;
					case SDLK_KP_6: eyePointMove.x += eyePointAcceleration.x; break;

					case SDLK_KP_8: eyePointMove.y -= eyePointAcceleration.y; break;
					case SDLK_KP_2: eyePointMove.y += eyePointAcceleration.y; break;

					case SDLK_m: simLength = 0.0002; break;
					
					case SDLK_p: std::cout << "Player 1 Score" << "\t" << "Player 2 Score" << "\n" << p1Score << "\t\t" << p2Score << "\n"; break;
					case SDLK_n: waypoint(); std::cout << random1 << " " << random2 << " " << random3 << "\n"; break;
				}
			break;

			//keyup handling
		case SDL_KEYUP:
			switch (_camEvent.key.keysym.sym)
			{
				//top tank 
				case SDLK_d:		translateSpeed.x -= translateAcceleration.x; cube1left -= translateAcceleration.x; cube1right -= translateAcceleration.x; break;
				case SDLK_a:		translateSpeed.x += translateAcceleration.x; cube1left += translateAcceleration.x; cube1right += translateAcceleration.x; break;

				case SDLK_w:		translateSpeed.y -= translateAcceleration.y; cube1top -= translateAcceleration.y; cube1bottom -= translateAcceleration.y; break;
				case SDLK_s:		translateSpeed.y += translateAcceleration.y; cube1top += translateAcceleration.y; cube1bottom += translateAcceleration.y; break;

				//case SDLK_q: rotateSpeed -= rotationAcceleration; break;
				//case SDLK_e: rotateSpeed += rotationAcceleration; break;

				//bottom tank 
				case SDLK_LEFT:		translateSpeed1.x += translateAcceleration1.x; cube2left += translateAcceleration.x; cube2right += translateAcceleration.x; break;
				case SDLK_RIGHT:	translateSpeed1.x -= translateAcceleration1.x; cube2left -= translateAcceleration.x; cube2right -= translateAcceleration.x; break;

				case SDLK_UP:		translateSpeed1.y -= translateAcceleration1.y; cube2top -= translateAcceleration.y; cube2bottom -= translateAcceleration.y; break;
				case SDLK_DOWN:		translateSpeed1.y += translateAcceleration1.y; cube2top += translateAcceleration.y; cube2bottom += translateAcceleration.y; break;

				//camera
				case SDLK_KP_5: eyePointMove.z += eyePointAcceleration.z; break;
				case SDLK_KP_0: eyePointMove.z -= eyePointAcceleration.z; break;

				case SDLK_KP_4: eyePointMove.x += eyePointAcceleration.x; break;
				case SDLK_KP_6: eyePointMove.x -= eyePointAcceleration.x; break;

				case SDLK_KP_8: eyePointMove.y += eyePointAcceleration.y; break;
				case SDLK_KP_2: eyePointMove.y -= eyePointAcceleration.y; break;

				case SDLK_m: simLength = 0.002; break;
			
			}
			break;
			//mouse handling

			SDL_PumpEvents();
			if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)) {

				mousePosX = _camEvent.motion.x;
				mousePosY = _camEvent.motion.y;

				horizontalAngle += (mouseSpeed * float(300 - mousePosX));
				verticalAngle += (mouseSpeed * float(300 - mousePosY));
				break;
			}

	
			break;

		default: //one dose not simply forget a default case
			break;

		}
	}
}

void Renderer::updateSim()
{
	glm::vec3 modelPositionW = glm::vec3(random1, random2, random3);
	glm::vec3 modelScaleW = glm::vec3(1.0f, 1.0f, 1.0f);
	float modelRotationZW = 0.0f; // angles in radians around Z


	const glm::vec3 unitX = glm::vec3(1, 0, 0);
	const glm::vec3 unitY = glm::vec3(0, 1, 0);
	const glm::vec3 unitZ = glm::vec3(0, 0, 1);
	const glm::vec3 unit45 = glm::normalize(glm::vec3(0, 0, 1));

	//update our representaion of the cube

	modelScale = modelScale; //if scale changes over time update it here

	float rotateNow = (float)simLength * rotateSpeed; //how much to rotate now?
	modelRotationZ += rotateNow; //apply

	glm::vec3 translateNow = float(simLength) * translateSpeed; //how much to translate now?
	modelPosition += translateNow;

	//calculate modelMatrix
	glm::mat4 scaleMatrix = glm::scale(modelScale); // set matrix to scale var
	glm::mat4 rotationMatrix = glm::rotate(modelRotationZ, unitZ);
	glm::mat4 translationMatrix = glm::translate(modelPosition);
	modelMatrix = translationMatrix * rotationMatrix * scaleMatrix;


	////1
	modelScale1 = modelScale1; //if scale changes over time update it here

	float rotateNow1 = (float)simLength * rotateSpeed1; //how much to rotate now?
	modelRotationZ1 += rotateNow1; //apply

	glm::vec3 translateNow1 = float(simLength) * translateSpeed1; //how much to translate now?
	modelPosition1 += translateNow1;

	//calculate modelMatrix
	glm::mat4 scaleMatrix1 = glm::scale(modelScale1); // set matrix to scale var
	glm::mat4 rotationMatrix1 = glm::rotate(modelRotationZ1, unitZ);
	glm::mat4 translationMatrix1 = glm::translate(modelPosition1);
	modelMatrix1 = translationMatrix1 * rotationMatrix1 * scaleMatrix1;


	//waypoint 
	float rotateNowW = (float)simLength * rotateSpeedW; //how much to rotate now?
	modelRotationZW += rotateNowW; //apply

	glm::vec3 translateNowW = float(simLength) * translateSpeedW; //how much to translate now?
	modelPositionW += translateNowW;

	//calculate modelMatrix
	glm::mat4 scaleMatrixW = glm::scale(modelScaleW); // set matrix to scale var
	glm::mat4 rotationMatrixW = glm::rotate(modelRotationZW, unitZ);
	glm::mat4 translationMatrixW = glm::translate(modelPositionW);
	modelMatrixW = translationMatrixW * rotationMatrixW * scaleMatrixW;
	
	

	

	//camera
	eyePoint += eyePointMove;

	glm::vec3 lookAtPoint(
		cos(verticalAngle) * sin(horizontalAngle),
		sin(verticalAngle),
		cos(verticalAngle) * cos(horizontalAngle)
		);

	glm::vec3 rightVar(
		sin(horizontalAngle - 3.14f / 2.0f),
		0,
		cos(horizontalAngle - 3.14f / 2.0f)
		);

	glm::vec3 upVector = glm::cross(rightVar, lookAtPoint);

	viewMatrix = glm::lookAt(eyePoint, (eyePoint + lookAtPoint), upVector);

	float fovyRadians = glm::radians(90.0f);
	float aspectRatio = 1.0f;
	float nearClipPlane = 0.1f;
	float farClipPlane = 100.0f;

	projectionMatrix = glm::perspective(fovyRadians, aspectRatio, nearClipPlane, farClipPlane);

	collisionGreen();
	collisionRed();

	/*
	if (p1Score <= 10){
		std::cout << "player 1 wins";
		system("Pause");
		SDL_Quit();
	}

	if (p2Score <= 10){
		std::cout << "player 2 wins";
		system("Pause");
		SDL_Quit();
	}
	*/
}

void Renderer::collisionGreen()
{
	if ((cube1top < wayY || cube1bottom > wayY) && (cube1left > wayX || cube1right < wayX)){
		//no collision
	}
	else
	{
		p1Score++;//give player point
		waypoint();// draw new waypoint
	}
}

void Renderer::collisionRed()
{
	if ((cube2top < wayY || cube2bottom > wayY) && (cube2left > wayX || cube2right < wayX)){
		//no collision
	}
	else
	{
		p2Score++;//give player point
		waypoint();// draw new waypoint
	}
}



void Renderer::waypoint(){
	random1 = -4.0f + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (4.0f - -4.0f)));	
	random2 = -4.0f + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (4.0f - -4.0f)));
}

GameState Renderer::getState() {
	return _GameState;
}
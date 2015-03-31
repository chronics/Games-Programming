#include "Renderer.h"

#include "vertexData.h"

//vertex object 1 params
glm::mat4 modelMatrix, viewMatrix, projectionMatrix, rotationMatrix, translationMatrix, modelMatrix1 ;

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
	sin(horizontalAngle - 3.14f / 2.0f),0,
	cos(horizontalAngle - 3.14f / 2.0f));




Renderer::Renderer()
{
}

Renderer::~Renderer()
{
}

std::string LoadShaderFromFile(const std::string& filename)
{
	std::ifstream file;
	std::string source;
	std::string line;

	file.open(filename);

	if (file.is_open())
	{
		while (file.good())
		{
			getline(file, line);
			source.append(line + "\n");
		}
	}
	else
	{
		std::cout << "Couldn't open shader: " << filename << std::endl;
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

	std::string vertexSource = LoadShaderFromFile("shaders/shader.vert");
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
	/*
	glGenBuffers(1, &vertexBufferObject2D);
		glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject2D);
		glBufferData(GL_ARRAY_BUFFER, sizeof(triangles), triangles, GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	*/

	glGenBuffers(1, &vertexBufferObject);
		glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
		glBufferData(GL_ARRAY_BUFFER, sizeof(tankbody), tankbody, GL_STATIC_DRAW);
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
	size_t colorData = sizeof(tankbody) / 2;
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject); 
	glVertexAttribPointer(positionLocation, 4, GL_FLOAT, GL_FALSE, 0, 0); 
	glVertexAttribPointer(colorLocation, 4, GL_FLOAT, GL_FALSE, 0, (void*)colorData); 
	glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, glm::value_ptr(modelMatrix));
	glDrawArrays(GL_TRIANGLES, 0, 36);

	glDisableVertexAttribArray(0); 
	glUseProgram(0);
}

void Renderer::camera()
{
	const glm::vec3 unitX = glm::vec3(1, 0, 0);
	const glm::vec3 unitY = glm::vec3(0, 1, 0);
	const glm::vec3 unitZ = glm::vec3(0, 0, 1);
	const glm::vec3 unit45 = glm::normalize(glm::vec3(0, 1, 1));

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
}

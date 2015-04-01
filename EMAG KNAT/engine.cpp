#include "engine.h"


Renderer _draw;
Renderer* _cam;


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

engine::engine()
{
	_window = nullptr;
	_screenWidth = 600;
	_screenHight = 600;
	_GameState = GameState::PLAY;
}

engine::~engine()
{
}


void engine::run()
{
	initSystem();
	createWindow();
	setAttributes(3, 3);
	createContext();
	initGlew();

	_draw.runShaders();

	gameLoop();
}

void engine::initSystem()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		fatalError("SDL_Init Error");
	}
}

void engine::createWindow()
{
	bool cam = true;

	std::cout << "Fullscreen will be set to 768p\nFullscreen? (y/n): ";
	char inputc = 'y';
	std::cin >> inputc;
	std::cout << "Loading... (this may take a while!) ...\n\n\n";

	if (inputc == 'y' || inputc == 'Y')
	{
		_window = SDL_CreateWindow("Games Programming", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 768, SDL_WINDOW_OPENGL | SDL_WINDOW_FULLSCREEN);
	}
	else
		_window = SDL_CreateWindow("Games Programming", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHight, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE );

	if (_window == nullptr)
	{
		fatalError("SDL Window failed to open!");
	}
}

void engine::setAttributes(int major, int minor)
{	
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, major);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, minor);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

}

void engine::createContext()
{
	context = SDL_GL_CreateContext(_window);
	if (context == nullptr)
	{
		SDL_DestroyWindow(_window);
		fatalError("Context Error!");
	}
}

void engine::initGlew()
{
	GLenum rev;
	glewExperimental = GL_TRUE;
	rev = glewInit();
	if (GLEW_OK != rev)
	{
		fatalError("InitGlew failed!");
	}

	// Enable back face culling with counter-clockwise winding for front faces
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);

	// Enable depth testing
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	// Enable vsync
	SDL_GL_SetSwapInterval(1);

	// Set clear color
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClearDepth(1.0f);

	//EasterEgg Command
	std::cout << "You want your freedom?\nTake it\nThat's what I'm counting on...\nI used to want you dead but\nNow I only want you gone...\n\n\n";

	std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "GLSL version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;

	std::cout << "\nVendor: " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "Graphics Card: " << glGetString(GL_RENDERER) << "\n" << std::endl;

	//i know its not ment to be hear but i need it!
	
}



void engine::processInput()
{
	SDL_Event _event;

	while (SDL_PollEvent(&_event)) { 
		switch (_event.type)
		{

		case SDL_QUIT:
			_GameState = GameState::EXIT;
			break;

			//keydown handling - we should to the opposite on key-up for direction controls (generally)
		case SDL_KEYDOWN:

			if (!_event.key.repeat)
				switch (_event.key.keysym.sym)
			{
				//hit escape to exit
				case SDLK_ESCAPE:
					_GameState = GameState::EXIT;

				case SDLK_KP_5: eyePointMove.z -= eyePointAcceleration.z; break;
				case SDLK_KP_0: eyePointMove.z += eyePointAcceleration.z; break;

				case SDLK_KP_6: eyePointMove.x -= eyePointAcceleration.x; break;
				case SDLK_KP_4: eyePointMove.x += eyePointAcceleration.x; break;

				case SDLK_KP_8: eyePointMove.y -= eyePointAcceleration.y; break;
				case SDLK_KP_2: eyePointMove.y += eyePointAcceleration.y; break;
			}
			break;

			//keyup handling
			case SDL_KEYUP:
				switch (_event.key.keysym.sym)
				{
				case SDLK_KP_5: eyePointMove.z += eyePointAcceleration.z; break;
				case SDLK_KP_0: eyePointMove.z -= eyePointAcceleration.z; break;

				case SDLK_KP_6: eyePointMove.x += eyePointAcceleration.x; break;
				case SDLK_KP_4: eyePointMove.x -= eyePointAcceleration.x; break;

				case SDLK_KP_8: eyePointMove.y += eyePointAcceleration.y; break;
				case SDLK_KP_2: eyePointMove.y -= eyePointAcceleration.y; break;
				}
				break;
			//mouse handling*/

		case SDL_MOUSEMOTION:
			{
			
			};
			break;

		default: //one dose not simply forget a default case
			break;
			
		}
	}
}

glm::mat4 _viewMatrix, _projectionMatrix;

void Renderer::camera(glm::mat4 viewMatrix, glm::mat4 projectionMatrix)
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

		_viewMatrix = viewMatrix;
		_projectionMatrix = projectionMatrix;
}


void engine::renderGame()
{
	glClearDepth(1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	_draw.render();
	

	SDL_GL_SwapWindow(_window);
}

void engine::gameLoop()
{
	while (_GameState != GameState::EXIT)
	{
		processInput();
		_cam->Renderer::camera(_viewMatrix, _projectionMatrix);
		renderGame();
	}
}

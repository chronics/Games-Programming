#include "engine.h"

Renderer _draw;

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
	/*std::cout << "Fullscreen will be set to 768p\nFullscreen? (y/n): ";
	char inputc = 'y';
	std::cin >> inputc;
	std::cout << "Loading... (this may take a while!) ...\n\n\n";

	if (inputc == 'y' || inputc == 'Y')
	{
	_window = SDL_CreateWindow("Games Programming", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 768, SDL_WINDOW_OPENGL | SDL_WINDOW_FULLSCREEN | SDL_WINDOW_SHOWN);
	}
	else*/
	_window = SDL_CreateWindow("Games Programming", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHight, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN);

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
	std::cout << "Set OpenGL and context to version " << major << "." << minor << " OK!\n\n";
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
}

void engine::processInput()
{
	SDL_Event evnt;

	while (SDL_PollEvent(&evnt))
	{
		switch (evnt.type)
		{
		case SDL_QUIT:
			_GameState = GameState::EXIT;
			break;
		case SDL_MOUSEMOTION:
			std::cout << evnt.motion.x << " " << evnt.motion.y << std::endl;
			break;
		}
	}
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
		renderGame();
	}
}
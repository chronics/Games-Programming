#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

#include <fstream>
#include <string>

#include <GL/glew.h>
#include <SDL2/SDL.h>

#define GLM_FORCE_RADIANS 

#include <glm/glm.hpp> 
#include <glm/gtc/matrix_transform.hpp> 
#include <glm/gtc/type_ptr.hpp> 

#include "Error.h"
#include "Renderer.h"

enum class GameState { PLAY, EXIT };

class engine
{
public:
	engine();
	~engine();

	int _screenWidth, _screenHight;

	SDL_Window* _window;
	SDL_GLContext context;
	GameState _GameState;

	void run();

private:

	void initSystem();

	void createWindow();
	void setAttributes(int major, int minor);
	void createContext();
	void initGlew();

	void gameLoop();

	void processInput();

	void renderGame();	
};


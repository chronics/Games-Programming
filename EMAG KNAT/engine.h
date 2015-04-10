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

#include "Renderer.h"
#include "Error.h"

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
	void renderGame();

private:

	void initSystem();

	void createWindow();
	void setAttributes(int major, int minor);
	void createContext();
	void initGlew();

	void gameLoop();

	void processInput();
	
	void runShaders();
	void render();

	void updateSim();
	void camInput();

	void initializeProgram();
	void initializeVertexBuffer();

	void camera();

	
};


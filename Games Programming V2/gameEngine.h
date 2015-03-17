#pragma once

#include <iostream>

#include <string>

#include <SDL2\SDL.h>
#include <GL\glew.h>

#include "Sprite.h"
#include "GLSLProgram.h"

enum class GameState {PLAY, EXIT};

class gameEngine
{
public:
	gameEngine();
	~gameEngine();

	void run();
	
private:
	int _screenWidth, _screenHight, major, minor;
	
	SDL_Window* _window;
	SDL_GLContext context;
	GameState _GameState;

	void initSystem();
	void initShaders();

	void createWindow();
	void setAttributes(int major,int minor);
	void createContext();
	void initGlew();
	void processInput();
	void gameLoop();
	
	void renderGame();

	Sprite _sprite;
	GLSLProgram _colourProgram;
};


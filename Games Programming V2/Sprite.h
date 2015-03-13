#pragma once

#include <iostream>

#include <string>

#include <SDL2\SDL.h>
#include <GL\glew.h>

class Sprite
{
public:
	Sprite();
	~Sprite();

	void init(float _spriteX, float _spriteY, float _spriteWidth, float _spriteHight);
	void draw();
	

private:
	float _X, _Y, _width, _hight;
	GLuint _VBOID;
};


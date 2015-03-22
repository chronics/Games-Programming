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

class window
{
public:
	window();
	~window();

	SDL_Window* _window;
	SDL_GLContext context;

	void initSystem();

private:

	void createWindow();
	void setAttributes();
	void createContext();
	void initGlew();

};

class loadAssets
{
public:
	loadAssets();
	~loadAssets();

	GLuint theProgram, vertexBufferObject, vertexBufferObject2D, vao;
	GLint positionLocation, colorLocation, modelMatrixLocation, viewMatrixLocation, projectionMatrixLocation;

	glm::mat4 modelMatrix, viewMatrix, projectionMatrix, rotationMatrix, translationMatrix;

	void initializeProgram();
	void initializeVertexBuffer();

private:

};

class render : public loadAssets
{
public:
	render();
	~render();

private:

};
#pragma once

#include "Error.h"
#include "engine.h"

class Renderer
{
public:
	Renderer();
	~Renderer();

	GLint positionLocation, colorLocation, modelMatrixLocation, viewMatrixLocation, projectionMatrixLocation;

	GLuint theProgram, vertexBufferObject, vertexBufferObject2D, vao;
	
	void runShaders();
	void render();

	void camera(glm::mat4 viewMatrix, glm::mat4 projectionMatrix);

private:

	void initializeProgram();
	void initializeVertexBuffer();

	
	
};


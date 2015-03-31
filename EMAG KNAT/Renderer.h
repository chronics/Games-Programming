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

	void camera();

private:

	void initializeProgram();
	void initializeVertexBuffer();

	
	
};


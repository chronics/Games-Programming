#pragma once

#include "engine.h"
#include "Error.h"

class Renderer
{
public:
	Renderer();
	~Renderer();

	glm::mat4 modelMatrix, viewMatrix, projectionMatrix, rotationMatrix, translationMatrix, modelMatrix1;

	GLint positionLocation, colorLocation, modelMatrixLocation, viewMatrixLocation, projectionMatrixLocation;

	GLuint theProgram, vertexBufferObject, vertexBufferObject2D, vao;
	
	void runShaders();
	void render();

	void updateSim();
	void camInput();

private:

	void initializeProgram();
	void initializeVertexBuffer();

	
};


#pragma once

#include "engine.h"
#include "Error.h"
#include "GameState.h"

class Renderer
{
public:
	Renderer();
	~Renderer();

	glm::mat4 modelMatrix, viewMatrix, projectionMatrix, rotationMatrix, translationMatrix, modelMatrix1, rotationMatrix1, translationMatrix1, modelMatrixW, rotationMatrixW, translationMatrixW;
	GLint positionLocation, colorLocation, modelMatrixLocation, viewMatrixLocation, projectionMatrixLocation;
	GLuint theProgram, vertexBufferObject, vertexBufferObject1, vertexBufferObject2D, vao;
	
	glm::mat4 cubeTransaltionMatrix, cubeTransaltionMatrix1;
	
	void runRender();

	void runShaders();
	void render();

	void updateSim();
	void renderInput();
	
	void waypoint();
	
	GameState getState();
	
private:

	void initializeProgram();
	void initializeVertexBuffer();
	void collisionGreen();
	void collisionRed();

	GameState _GameState;
};


#pragma once

#include "engine.h"
#include "Error.h"

//enum class GameState { PLAY, EXIT };

class Renderer
{
public:
	Renderer();
	~Renderer();

	

	glm::mat4 modelMatrix, viewMatrix, projectionMatrix, rotationMatrix, translationMatrix, modelMatrix1, rotationMatrix1, translationMatrix1;
	GLint positionLocation, colorLocation, modelMatrixLocation, viewMatrixLocation, projectionMatrixLocation;
	GLuint theProgram, vertexBufferObject, vertexBufferObject2D, vao;
	
	void runRender();

	void runShaders();
	void render();

	void updateSim();
	void renderInput();
	//void gameLoop();


private:

	void initializeProgram();
	void initializeVertexBuffer();

	
};


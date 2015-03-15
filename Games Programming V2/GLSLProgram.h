#pragma once
#include <string>
#include <GL/glew.h>

class GLSLProgram
{
public:
	GLSLProgram();
	~GLSLProgram();

	void createShader(const std::string& filepathV, const std::string& filepathF);
	void linkShaders();

private:
	GLuint _programID, _vertexID, _fragmentID;

	void compileShaders(const std::string _filePath, GLuint _ID);
};


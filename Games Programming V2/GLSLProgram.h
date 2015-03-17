#pragma once
#include <string>
#include <GL/glew.h>

class GLSLProgram
{
public:
	GLSLProgram();
	~GLSLProgram();

	void linkShaders();
	void createShader(const std::string& filepathV, const std::string& filepathF);
	void addAttribute(const std::string& attributename);

	void use();
	void unuse();

private:
	int _numAttributes;
	GLuint _programID;
	GLuint _vertexID;
	GLuint _fragmentID;
	

	void compileShaders(const std::string _filePath, GLuint _ID);
};


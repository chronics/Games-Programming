#include "GLSLProgram.h"
#include "Error.h"

#include <iostream>
#include <vector>
#include <fstream>

GLSLProgram::GLSLProgram() : _programID(0), _vertexID(0), _fragmentID(0)
{
	
}


GLSLProgram::~GLSLProgram()
{
}

void GLSLProgram::createShader(const std::string& filepathV, const std::string& filepathF)
{
	_vertexID = glCreateShader(GL_VERTEX_SHADER);
	if (_vertexID == 0)
	{
		fatalError("shader.vert failed to load!");
	}

	_fragmentID = glCreateShader(GL_FRAGMENT_SHADER);
	if (_vertexID == 0)
	{
		fatalError("shader.frag failed to load!");
	}

	compileShaders(filepathV, _vertexID);
	compileShaders(filepathF, _fragmentID);

}

void GLSLProgram::linkShaders()
{
	//https://www.youtube.com/watch?v=LLUtSE2osfI //24.30
}

void GLSLProgram::compileShaders(const std::string _filePath, GLuint _ID)
{
	std::ifstream vertexFile(_filePath);
	if (vertexFile.fail())
	{
		perror(_filePath.c_str());
		fatalError("Failed to open" + _filePath);
	}

	std::string _file, _line;

	while (std::getline(vertexFile, _line))
	{
		_file += _line + "\n";
	}

	vertexFile.close();

	const char* filePtr = _file.c_str();
	glShaderSource(_ID, 1, &filePtr, nullptr);

	glCompileShader(_ID);

	GLint isCompiled = 0;
	glGetShaderiv(_ID, GL_COMPILE_STATUS, &isCompiled);

	if (isCompiled == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetShaderiv(_ID, GL_INFO_LOG_LENGTH, &maxLength);

		std::vector<char> errorLog(maxLength);
		glGetShaderInfoLog(_ID, maxLength, &maxLength, &errorLog[0]);

		glDeleteShader(_ID);

		std::printf("%s\n", &errorLog[0]);
		fatalError("Shader" + _filePath + " failed");

	}

}
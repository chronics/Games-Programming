#include "GLSLProgram.h"
#include "Error.h"

#include <iostream>
#include <vector>
#include <fstream>

GLSLProgram::GLSLProgram() : _numAttributes(0), _programID(0), _vertexID(0), _fragmentID(0)
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
	_programID = glCreateProgram();

	
	glAttachShader(_programID, _vertexID);
	glAttachShader(_programID, _fragmentID);

	glLinkProgram(_programID);

	GLint isLinked = 0;

	glGetProgramiv(_programID, GL_LINK_STATUS, (int *)&isLinked);
	if (isLinked == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetProgramiv(_programID, GL_INFO_LOG_LENGTH, &maxLength);

		std::vector<char> errorLog(maxLength);
		glGetProgramInfoLog(_programID, maxLength, &maxLength, &errorLog[0]);

		glDeleteProgram(_programID);
		
		glDeleteShader(_vertexID);
		glDeleteShader(_fragmentID);

		std::printf("%s\n", &(errorLog[0]));
		fatalError("Shaders failed to link!");
	}

	glDetachShader(_programID, _vertexID);
	glDetachShader(_programID, _fragmentID);

	glDeleteShader(_vertexID);
	glDeleteShader(_fragmentID);
}

void GLSLProgram::addAttribute(const std::string& attributename)
{
	glBindAttribLocation(_programID, _numAttributes++, attributename.c_str());
}

void GLSLProgram::use()
{
	glUseProgram(_programID);
	for (int i = 0; i < _numAttributes; i++)
	{
		glEnableVertexAttribArray(i);
	}
}

void GLSLProgram::unuse()
{
	glUseProgram(0);
	for (int i = 0; i < _numAttributes; i++)
	{
		glDisableVertexAttribArray(i);
	}
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
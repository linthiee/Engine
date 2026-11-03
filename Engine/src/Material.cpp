#include "GL/glew.h"
#include "Material.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::string Material::ReadFile(const char* filepath)
{
	std::ifstream stream(filepath);
	if (!stream.is_open())
	{
		std::cout << "ERROR::SHADER::FILE_NOT_FOUND: " << filepath << std::endl;
		return "";
	}

	std::stringstream stringStream;
	stringStream << stream.rdbuf();
	return stringStream.str();
}

unsigned int Material::CompileShader(unsigned int type, const std::string& source)
{
	unsigned int id = glCreateShader(type);
	const char* src = source.c_str();
	glShaderSource(id, 1, &src, NULL);
	glCompileShader(id);

	int success;
	char infoLog[512];
	glGetShaderiv(id, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(id, 512, NULL, infoLog);
		const char* typeName = (type == GL_VERTEX_SHADER) ? "VERTEX" : "FRAGMENT";
		std::cout << "ERROR::SHADER::" << typeName << "::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	return id;
}

Material::Material()
{
}

Material::Material(const char* vertexPath, const char* fragmentPath)
{
	LoadVertexShader(vertexPath);
	LoadFragmentShader(fragmentPath);
	CreateMaterialProgram();
}

Material::~Material()
{
	if (shaderProgram != 0)
	{
		glDeleteProgram(shaderProgram);
	}
}

void Material::LoadVertexShader(const char* vertexPath)
{
	std::string vertexSource = ReadFile(vertexPath);
	vertexShader = CompileShader(GL_VERTEX_SHADER, vertexSource);
}

void Material::LoadFragmentShader(const char* fragmentPath)
{
	std::string fragmentSource = ReadFile(fragmentPath);
	fragmentShader = CompileShader(GL_FRAGMENT_SHADER, fragmentSource);
}

void Material::CreateMaterialProgram()
{
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	int success;
	char infoLog[512];
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	vertexShader = 0;
	fragmentShader = 0;
}

void Material::SetUniformMat4f(const char* name, const glm::mat4x4& matrix)
{
	Bind();
	glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, &matrix[0][0]);
}

void Material::SetUniform1i(const char* name, int value)
{
	Bind();
	glUniform1i(GetUniformLocation(name), value);
}

int Material::GetUniformLocation(const char* name)
{
	std::string sName = name;

	int location = glGetUniformLocation(shaderProgram, sName.c_str());

	return location;
}

void Material::Bind()
{
	glUseProgram(shaderProgram);
}

void Material::Unbind()
{
	glUseProgram(0);
}
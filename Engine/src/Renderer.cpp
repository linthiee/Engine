#include "GL/glew.h"
#include "Renderer.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

struct ShaderSource
{
	std::string VertexSource;
	std::string FragmentSource;
};

static ShaderSource ParseShader(const std::string& filepath)
{
	std::ifstream stream(filepath);

	enum class ShaderType
	{
		NONE = -1, VERTEX = 0, FRAGMENT = 1
	};

	std::string line;
	std::stringstream ss[2];
	ShaderType shaderType = ShaderType::NONE;

	while (getline(stream, line))
	{
		if (line.find("#shader") != std::string::npos)
		{
			if (line.find("vertex") != std::string::npos) 
			{
				shaderType = ShaderType::VERTEX;
			}
			else if (line.find("fragment") != std::string::npos)
			{
				shaderType = ShaderType::FRAGMENT;
			}
		}
		else if (shaderType != ShaderType::NONE)
		{
			ss[(int)shaderType] << line << '\n';
		}
	}

	return { ss[0].str(), ss[1].str() };
}

Renderer::Renderer(Window* window)
{
	renderWindow = window;
}

void Renderer::InitShaders()
{
	ShaderSource source = ParseShader("res/Shaders/Basic.shader");

	const char* vertexShaderSource = source.VertexSource.c_str();

	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	int success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	const char* fragmentShaderSource = source.FragmentSource.c_str();
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void Renderer::Render()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::Draw(int vertexCount)
{
	glUseProgram(shaderProgram);

	glDrawArrays(GL_TRIANGLES, 0, vertexCount);
}
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

	projection = glm::ortho(-2.0f, 2.0f, -1.5f, 1.5f, -1.0f, 1.0f);
	view = glm::translate(glm::identity<glm::mat4>(), glm::vec3(0.5, 0, 0));
	model = glm::translate(glm::identity<glm::mat4>(), glm::vec3(0.5, 0.5, 0));

	mvp = projection * view * model;
}

void Renderer::InitShaders(const char* shader)
{
	std::string path(shader);
	ShaderSource source = ParseShader(path);

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

void Renderer::Draw(int indices)
{
	glUseProgram(shaderProgram);

	glDrawElements(GL_TRIANGLES, indices, GL_UNSIGNED_INT, nullptr);
}

void Renderer::SetUniformMat4f(const char* name, const glm::mat4x4& matrix)
{
	glUseProgram(shaderProgram);
	glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, &matrix[0][0]);
}

int Renderer::GetUniformLocation(const char* name)
{
	std::string sName = name;

	int location = glGetUniformLocation(shaderProgram, sName.c_str());

	return location;
}

glm::mat4x4 Renderer::getMVPMatrix4x4() const
{
	return mvp;
}

glm::mat4x4 Renderer::getProjectionMat4x4() const
{
	return projection;
}

glm::mat4x4 Renderer::getViewMat4x4() const
{
	return view;
}

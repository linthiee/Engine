#include "GL/glew.h"
#include "Material.h"
#include <fstream>
#include <sstream>
#include <iostream>

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

Material::Material()
{
}

Material::Material(const char* shaderPath)
{
	std::string path(shaderPath);
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

Material::~Material()
{
	glDeleteProgram(shaderProgram);
}

void Material::SetUniformMat4f(const char* name, const glm::mat4x4& matrix)
{
	Bind();
	glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, &matrix[0][0]);
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
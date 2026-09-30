#pragma once
#include "Export.h"

#include <string>

#include "glm/glm.hpp"

struct ShaderSource
{
	std::string VertexSource;
	std::string FragmentSource;
};

class BASEGAME_API Material
{
private:

	unsigned int vertexShader;
	unsigned int fragmentShader;
	unsigned int shaderProgram;

public:

	Material();
	Material(const char* shaderPath);
	~Material();

	void SetUniformMat4f(const char* name, const glm::mat4x4& matrix);
	int GetUniformLocation(const char* name);

	void Bind();
	void Unbind();
};


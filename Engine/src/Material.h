#pragma once
#include "Export.h"

#include <string>

#include "glm/glm.hpp"

class BASEGAME_API Material
{
private:
	unsigned int shaderProgram = 0;
	unsigned int vertexShader = 0;
	unsigned int fragmentShader = 0;

	std::string ReadFile(const char* filepath);
	unsigned int CompileShader(unsigned int type, const std::string& source);
public:

	Material();
	Material(const char* vertexPath, const char* fragmentPath);
	~Material();

	void LoadVertexShader(const char* vertexPath);
	void LoadFragmentShader(const char* fragmentPath);
	void CreateMaterialProgram();

	void SetUniformMat4f(const char* name, const glm::mat4x4& matrix);
	void SetUniform1i(const char* name, int value);
	int GetUniformLocation(const char* name);

	void Bind();
	void Unbind();
};


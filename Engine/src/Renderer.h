#pragma once
#include "Window.h"

#include <vector>
#include <string>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

class Renderer
{
private:
	Window* renderWindow;

	unsigned int vertexShader;
	unsigned int fragmentShader;
	unsigned int shaderProgram;

	glm::mat4x4 projection;
	glm::mat4x4 view;
	glm::mat4x4 model;
	glm::mat4x4 mvp;

public:
	Renderer(Window* window);
	
	void InitShaders(std::string& shader);
	void Render();
	void Draw(int vertexCount);

	void SetUniformMat4f(const std::string& name, const glm::mat4x4& matrix);
	int GetUniformLocation(const std::string& name);

	glm::mat4x4 getMVPMatrix4x4() const;
};


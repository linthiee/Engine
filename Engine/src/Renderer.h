#pragma once
#include "Window.h"

#include <vector>

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

public:
	Renderer(Window* window);
	
	void InitShaders();
	void Render();
	void Draw(int vertexCount);

	//void SetUniformMat4f(const std::string& name, glm::mat4x4& matrix);
};


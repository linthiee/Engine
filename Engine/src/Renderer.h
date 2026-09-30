#pragma once
#include "Window.h"

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
	
	void InitShaders(const char* shader);
	void Render();
	void Draw(int indices);

	void SetUniformMat4f(const char* name, const glm::mat4x4& matrix);
	int GetUniformLocation(const char* name);

	glm::mat4x4 getMVPMatrix4x4() const;
	glm::mat4x4 getProjectionMat4x4() const;
	glm::mat4x4 getViewMat4x4() const;
};


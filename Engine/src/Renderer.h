#pragma once
#include "Window.h"
#include "Material.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

class Renderer
{
private:
	Window* renderWindow;
	Material* material;

	glm::mat4x4 projection;
	glm::mat4x4 view;
	glm::mat4x4 model;
	glm::mat4x4 mvp;

public:
	Renderer(Window* window);
	
	void Render();
	void Draw(int indices);

	glm::mat4x4 getMVPMatrix4x4() const;
	glm::mat4x4 getProjectionMat4x4() const;
	glm::mat4x4 getViewMat4x4() const;
};


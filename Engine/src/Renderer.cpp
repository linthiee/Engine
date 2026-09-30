#include "GL/glew.h"
#include "Renderer.h"
#include <GLFW/glfw3.h>
#include <iostream>

Renderer::Renderer(Window* window)
{
	renderWindow = window;

	projection = glm::ortho(-2.0f, 2.0f, -1.5f, 1.5f, -1.0f, 1.0f);
	view = glm::translate(glm::identity<glm::mat4>(), glm::vec3(0.5, 0, 0));
	model = glm::translate(glm::identity<glm::mat4>(), glm::vec3(0.5, 0.5, 0));

	mvp = projection * view * model;
}

void Renderer::Render()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::Draw(int indices)
{
	glDrawElements(GL_TRIANGLES, indices, GL_UNSIGNED_INT, nullptr);
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

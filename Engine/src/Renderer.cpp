#include "GL/glew.h"
#include "Renderer.h"
#include <GLFW/glfw3.h>
#include <iostream>

Renderer::Renderer()
{
	projection = glm::ortho(-2.0f, 2.0f, -1.5f, 1.5f, -1.0f, 1.0f);
	view = glm::lookAt(glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
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

void Renderer::InitBuffers(const float* positions, int posSizeInBytes, const unsigned int* indices, int indicesSizeInBytes, unsigned int& vao, unsigned int& vbo, unsigned int& ibo)
{
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, posSizeInBytes, positions, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)0);

	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesSizeInBytes, indices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)(2 * sizeof(float)));

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Renderer::BindVAO(unsigned int vao)
{
	glBindVertexArray(vao);
}

void Renderer::DeleteBuffers(unsigned int& vao, unsigned int& vbo, unsigned int& ibo)
{
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
	glDeleteBuffers(1, &ibo);
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

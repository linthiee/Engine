#include "GL/glew.h"
#include "Renderer.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include "Entity2D.h"

Renderer::Renderer()
{
	
}

void Renderer::Init(const int width, const int height)
{
	float orthoSize = 5.0f;
	aspectRatio = static_cast<float>(width) / static_cast<float>(height);

	projection = glm::ortho(-orthoSize * aspectRatio, orthoSize * aspectRatio, -orthoSize, orthoSize, 0.1f, 100.0f);
	view = glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void Renderer::Render()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::Draw(int indices)
{
	glDrawElements(GL_TRIANGLES, indices, GL_UNSIGNED_INT, nullptr);
}

//void Renderer::InitSpriteBuffers(const float* positions, int posSizeInBytes, const unsigned int* indices, int indicesSizeInBytes, unsigned int& vao, unsigned int& vbo, unsigned int& ibo)
//{
//	glGenVertexArrays(1, &vao);
//	glBindVertexArray(vao);
//
//	glGenBuffers(1, &vbo);
//	glBindBuffer(GL_ARRAY_BUFFER, vbo);
//	glBufferData(GL_ARRAY_BUFFER, posSizeInBytes, positions, GL_STATIC_DRAW);
//
//	glGenBuffers(1, &ibo);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesSizeInBytes, indices, GL_STATIC_DRAW);
//
//	int stride = // 2 pos + 3 color + 2 texCoords (UV)
//
//	// Layout 0: Posición (X, Y)
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, stride, (void*)0);
//
//	// Layout 1: Color (R, G, B)
//	glEnableVertexAttribArray(1);
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, stride, (void*)(2 * sizeof(float)));
//
//	// Layout 2: Coordenadas de Textura (U, V)
//
//
//	glBindVertexArray(0);
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
//}

void Renderer::InitBuffers(const float* positions, int posSizeInBytes, const unsigned int* indices, int indicesSizeInBytes, unsigned int& vao, unsigned int& vbo, unsigned int& ibo)
{
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, posSizeInBytes, positions, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 7, (void*)0);

	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesSizeInBytes, indices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 7, (void*)(2 * sizeof(float)));

	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 7, (void*)(5 * sizeof(float)));

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

glm::mat4x4 Renderer::getProjectionMat4x4() const
{
	return projection;
}

glm::mat4x4 Renderer::getViewMat4x4() const
{
	return view;
}

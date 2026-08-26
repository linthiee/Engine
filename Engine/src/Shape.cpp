#define GLFW_INCLUDE_NONE
#include <GL/glew.h>
#include "Shape.h"

Shape::Shape(Renderer* renderer, int vertexCount, float position[]) : Entity2D(renderer)
{
	for (int i = 0; i <= vertexCount; i++)
	{
		this->positions.push_back(position[i]);
	}
}

Shape::Shape(Renderer* renderer, int vertexCount) : Entity2D(renderer)
{
	float positions[6] =
	{
		 -0.5f, -0.5f,
		 0.5f, -0.5f,
		 0.0f,  0.5f,
	};

	for (int i = 0; i <= vertexCount; i++)
	{
		this->positions.push_back(positions[i]);
	}
}

Shape::~Shape()
{
}

void Shape::InitBuffer()
{
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);

	glBufferData(GL_ARRAY_BUFFER, positions.size() * sizeof(float), positions.data(), GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, (void*)0);
}

void Shape::Draw()
{
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, (void*)0);

	Entity::Draw(positions.size());
}

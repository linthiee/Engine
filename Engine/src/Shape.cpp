#define GLFW_INCLUDE_NONE
#include <GL/glew.h>
#include "Shape.h"

Shape::Shape() : Entity2D(renderer)
{
	this->indices = new std::vector<unsigned int>();
	this->positions = new std::vector<float>();
}

Shape::Shape(Renderer* renderer, int floatCount, float position[], int indexCount, int indices[]) : Entity2D(renderer)
{
	this->indices = new std::vector<unsigned int>();
	this->positions = new std::vector<float>();

	for (int i = 0; i < floatCount; i++)
	{
		this->positions->push_back(position[i]);
	}

	for (int i = 0; i < indexCount; i++)
	{
		this->indices->push_back(indices[i]);
	}
}

Shape::Shape(Renderer* renderer, int vertexCount) : Entity2D(renderer)
{
	this->indices = new std::vector<unsigned int>();
	this->positions = new std::vector<float>();

	float positions[] =
	{
		 -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
		 0.5f, -0.5f, 0.0f , 1.0f, 0.0f,
		 0.0f,  0.5f, 0.0f, 0.0f , 1.0f,
		 -0.5f, 0.5f, 1.0f, 0.0f, 1.0f
	};

	int indices[] =
	{
		0, 1, 2,
	};

	for (int i = 0; i < sizeof(indices) / sizeof(int); i++)
	{
		this->indices->push_back(indices[i]);
	}

	for (int i = 0; i < sizeof(positions) / sizeof(float); i++)
	{
		this->positions->push_back(positions[i]);
	}
}

Shape::~Shape()
{

}

void Shape::InitBuffer()
{
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);

	glBufferData(GL_ARRAY_BUFFER, positions->size() * sizeof(float), positions->data(), GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)0);

	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices->size() * sizeof(int), indices->data(), GL_STATIC_DRAW);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)(2 * sizeof(float)));

	glBindVertexArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Shape::Draw()
{
	glBindVertexArray(vao);
	Entity::Draw(indices->size());
}

void Shape::Destroy()
{
	delete positions;
	delete indices;
}

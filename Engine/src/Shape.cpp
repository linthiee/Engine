#include "Shape.h"

Shape::Shape(Renderer* renderer) : Entity2D(renderer)
{
}

Shape::~Shape()
{
	Destroy();
}

void Shape::InitBuffer()
{
	renderer->InitBuffers(positions.data(), positions.size() * sizeof(float), indices.data(), indices.size() * sizeof(unsigned int), vao, buffer, ibo);
}

void Shape::Draw()
{
	renderer->BindVAO(vao);
	Entity::Draw(indices.size());
}

void Shape::Destroy()
{
	if (vao != 0)
	{
		renderer->DeleteBuffers(vao, buffer, ibo);
		vao = 0;
	}
	positions.clear();
	indices.clear();
}
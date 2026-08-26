#pragma once
#include "Entity2D.h"

#include <vector>

class Shape : Entity2D
{
private:	
	std::vector<float> positions;
	unsigned int buffer;

public:
	Shape(Renderer* renderer, int vertexCount, float position[]);
	Shape(Renderer* renderer, int vertexCount);

	~Shape();

	void InitBuffer();

	void Draw();
};
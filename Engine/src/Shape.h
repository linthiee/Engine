#pragma once

#include "Export.h"
#include "Entity2D.h"

#include <vector>

class BASEGAME_API Shape : Entity2D
{
private:	
	std::vector<float> positions;
	unsigned int buffer;

public:
	Shape();
	Shape(Renderer* renderer, int vertexCount, float position[]);
	Shape(Renderer* renderer, int vertexCount);

	~Shape();

	void InitBuffer();

	void Draw();
};
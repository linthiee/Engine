#pragma once
#include "Export.h"
#include "Entity2D.h"
#include <vector>

class BASEGAME_API Shape : public Entity2D
{
protected:
	std::vector<float> positions;
	std::vector<unsigned int> indices;

	unsigned int vao = 0;
	unsigned int buffer = 0; // vbo
	unsigned int ibo = 0;

public:
	Shape(Renderer* renderer);
	virtual ~Shape();

	void InitBuffer();
	virtual void Draw();
	void Destroy();
};
#pragma once
#include "Entity2D.h"

#include <vector>

class BASEGAME_API Shape : public Entity2D
{
private:	
	std::vector<float>* positions;
	std::vector<unsigned int>* indices;

	unsigned int buffer;
	unsigned int ibo;
	unsigned int vao;

public:
	Shape();
	Shape(Renderer* renderer, int floatCount, float position[], int indexCount, int indices[]);
	Shape(Renderer* renderer, int vertexCount);

	~Shape();

	void InitBuffer();

	void Draw();

	void Destroy();
};
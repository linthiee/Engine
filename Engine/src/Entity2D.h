#pragma once
#include "Entity.h"

class Entity2D : protected Entity
{
public:
	Entity2D(Renderer* renderer);

	void Draw();
};


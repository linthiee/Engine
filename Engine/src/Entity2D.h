#pragma once
#include "Entity.h"

class BASEGAME_API Entity2D : public Entity
{
public:
	Entity2D(Renderer* renderer);

	void Draw();
};


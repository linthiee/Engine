#pragma once
#include "Export.h"

struct  Vector2
{
	float x;
	float y;

	Vector2()
	{
		x = 0;
		y = 0;
	}
	Vector2(float x, float y)
	{
		this->x = x;
		this->y = y;
	}
};

Vector2 BASEGAME_API Normalize(Vector2 vector);
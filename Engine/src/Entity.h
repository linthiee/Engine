#pragma once
#include "Coord.h"
#include "Renderer.h"

class Entity 
{
protected:
	Renderer* renderer;

	Vector2 pos;
	Vector2 rot;
	Vector2 scale;

public:
	Entity(Renderer* renderer);
	Entity(Renderer* renderer, Vector2 pos, Vector2 rot, Vector2 scale);

	virtual void Draw(int vertexCount);

	Vector2 getPos();
	void setPos(Vector2 pos);

	Vector2 getRot();
	void setRot(Vector2 ros);

	Vector2 getScale();
	void setScale(Vector2 scale);
};


#pragma once
#include "Export.h"

#include "Coord.h"
#include "Renderer.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class BASEGAME_API Entity
{
protected:
	Renderer* renderer;

	Vector2 pos;
	Vector2 rot;
	Vector2 scale;

	glm::mat4 model;

public:
	Entity(Renderer* renderer);
	Entity(Renderer* renderer, Vector2 pos, Vector2 rot, Vector2 scale);

	virtual void Draw(int vertexCount);

	Vector2 getPos();
	void setPos(Vector2 pos);

	Vector2 getRot();
	void setRot(Vector2 rot);

	Vector2 getScale();
	void setScale(Vector2 scale);

	glm::mat4 getTRSMatrix();
};


#pragma once
#include "Export.h"

#include "Vector2.h"
#include "Vector3.h"
#include "Renderer.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class BASEGAME_API Entity
{
protected:
	Renderer* renderer;

	Vector2 pos;
	Vector3 rot;
	Vector2 scale;

	glm::mat4 trs;
	bool isDirty;

public:
	Entity(Renderer* renderer);
	Entity(Renderer* renderer, Vector2 pos, Vector3 rot, Vector2 scale);
	virtual ~Entity();

	Vector2 getPos();
	void setPos(Vector2 pos);

	Vector3 getRot();
	void setRot(Vector3 rot);

	Vector2 getScale();
	void setScale(Vector2 scale);

	glm::mat4 getTRSMatrix();

};


#include "Entity.h"

Entity::Entity(Renderer* renderer)
{
	this->renderer = renderer;

	this->pos = { 0.0f, 0.0f };
	this->rot = { 0.0f, 0.0f, 0.0f };;
	this->scale = { 1.0f, 1.0f };;

	isDirty = true;
}

Entity::Entity(Renderer* renderer, Vector2 pos, Vector3 rot, Vector2 scale)
{
	this->renderer = renderer;

	this->pos = pos;
	this->rot = rot;
	this->scale = scale;

	isDirty = true;
}

Entity::~Entity()
{
}

Vector2 Entity::getPos()
{
	return pos;
}

void Entity::setPos(Vector2 pos)
{
	this->pos = pos;
	isDirty = true;
}

Vector3 Entity::getRot()
{
	return rot;
}

void Entity::setRot(Vector3 rot)
{
	this->rot = rot;
	isDirty = true;
}

Vector2 Entity::getScale()
{
	return scale;
}

void Entity::setScale(Vector2 scale)
{
	this->scale = scale;
	isDirty = true;
}

glm::mat4 Entity::getTRSMatrix()
{
	if (isDirty)
	{
		trs = glm::translate(glm::identity<glm::mat4>(), glm::vec3(pos.x, pos.y, 0.0f));

		trs = glm::rotate(trs, glm::radians(rot.x), glm::vec3(1.0f, 0.0f, 0.0f));
		trs = glm::rotate(trs, glm::radians(rot.y), glm::vec3(0.0f, 1.0f, 0.0f));
		trs = glm::rotate(trs, glm::radians(rot.z), glm::vec3(0.0f, 0.0f, 1.0f));

		trs = glm::scale(trs, glm::vec3(scale.x, scale.y, 1.0f));

		isDirty = false;
	}

	return trs;
}

#include "Entity.h"

Entity::Entity(Renderer* renderer)
{
	this->renderer = renderer;
}

Entity::Entity(Renderer* renderer, Vector2 pos, Vector2 rot, Vector2 scale)
{
	this->pos = pos;
	this->rot = rot;
	this->scale = scale;

	this->renderer = renderer;
}

void Entity::Draw(int vertexCount)
{
	renderer->Draw(vertexCount);
}

Vector2 Entity::getPos()
{
	return pos;
}

void Entity::setPos(Vector2 pos)
{
}

Vector2 Entity::getRot()
{
	return rot;
}

void Entity::setRot(Vector2 ros)
{
}

Vector2 Entity::getScale()
{
	return scale;
}

void Entity::setScale(Vector2 scale)
{
}

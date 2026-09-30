#include "Entity.h"

Entity::Entity(Renderer* renderer)
{
	this->renderer = renderer;
}

Entity::Entity(Renderer* renderer, Vector2 pos, Vector2 rot, Vector2 scale)
{
	this->renderer = renderer;

	this->pos = pos;
	this->rot = rot;
	this->scale = scale;
}

void Entity::Draw(int vertexCount)
{
	glm::mat4 viewProj = renderer->getProjectionMat4x4() * renderer->getViewMat4x4();
	glm::mat4 world = viewProj * getTRSMatrix();

	renderer->SetUniformMat4f("u_MVP", world);
	renderer->Draw(vertexCount);
}

Vector2 Entity::getPos()
{
	return pos;
}

void Entity::setPos(Vector2 pos)
{
	this->pos = pos;
}

Vector2 Entity::getRot()
{
	return rot;
}

void Entity::setRot(Vector2 rot)
{
	this->rot = rot;
}

Vector2 Entity::getScale()
{
	return scale;
}

void Entity::setScale(Vector2 scale)
{
	this->scale = scale;
}

glm::mat4 Entity::getTRSMatrix()
{
	model = glm::translate(glm::identity<glm::mat4>(), glm::vec3(pos.x, pos.y, 0.0f));
	model = glm::rotate(model, glm::radians(rot.x), glm::vec3(0.0f, 0.0f, 1.0f));
	model = glm::scale(model, glm::vec3(scale.x, scale.y, 1.0f));

	return model;
}

#include "Entity2D.h"

Entity2D::Entity2D(Renderer* renderer) : Entity(renderer)
{
	this->renderer = renderer;
	material = nullptr;
}

Entity2D::Entity2D(Renderer* renderer, Vector2 pos, Vector3 rot, Vector2 scale) : Entity(renderer)
{
	this->renderer = renderer;
	pos = { 0.0f, 0.0f };
	rot = { 0.0f, 0.0f, 0.0f };
	scale = { 1.0f, 1.0f };
}

Entity2D::~Entity2D()
{
}

void Entity2D::Draw(int vertexCount)
{
	if (!material)
		return;

	glm::mat4 mvp = renderer->getProjectionMat4x4() * renderer->getViewMat4x4() * getTRSMatrix();
	material->SetUniformMat4f("u_MVP", mvp);

	renderer->Draw(vertexCount);
}

void Entity2D::setMaterial(Material* material)
{
	this->material = material;
}

Material* Entity2D::getMaterial() const
{
	return material;
}

void Entity2D::setColliderScale(Vector2 colliderScale)
{
	this->colliderScale = colliderScale;
}

Vector2 Entity2D::getColliderScale() const
{
	 return colliderScale; 
}

AABB Entity2D::getAABB() const
{
	float halfWidth = scale.x * colliderScale.x;
	float halfHeight = scale.y * colliderScale.y;

	AABB box;
	box.minX = pos.x - halfWidth;
	box.maxX = pos.x + halfWidth;
	box.minY = pos.y - halfHeight;
	box.maxY = pos.y + halfHeight;

	return box;
}

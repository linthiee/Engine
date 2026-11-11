#pragma once
#include "Entity.h"

struct AABB
{
	float minX;
	float maxX;
	float minY;
	float maxY;
};

class BASEGAME_API Entity2D : public Entity
{
protected:
	Material* material;

	Vector2 colliderScale = { 0.5f, 0.5f };

public:
	Entity2D(Renderer* renderer);
	Entity2D(Renderer* renderer, Vector2 pos, Vector3 rot, Vector2 scale);
	virtual ~Entity2D();

	virtual void Draw(int vertexCount);

	void setMaterial(Material* material);
	Material* getMaterial() const;

	void setColliderScale(Vector2 colliderScale);
	Vector2 getColliderScale() const;
	AABB getAABB() const;
};


#pragma once
#include "Entity.h"

class BASEGAME_API Entity2D : public Entity
{
protected:
	Material* material;

public:
	Entity2D(Renderer* renderer);
	Entity2D(Renderer* renderer, Vector2 pos, Vector3 rot, Vector2 scale);
	virtual ~Entity2D();

	virtual void Draw(int vertexCount);

	void setMaterial(Material* material);
	Material* getMaterial() const;
};


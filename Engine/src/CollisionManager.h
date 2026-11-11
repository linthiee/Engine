#pragma once
#include "Entity2D.h"
#include "Export.h"

class BASEGAME_API CollisionManager
{
public:
	CollisionManager();
	~CollisionManager();

	bool CheckAABB(Entity2D* a, Entity2D* b);
};
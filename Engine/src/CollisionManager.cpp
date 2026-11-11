#include "CollisionManager.h"

CollisionManager::CollisionManager() {}

CollisionManager::~CollisionManager() {}

bool CollisionManager::CheckAABB(Entity2D* a, Entity2D* b)
{
	if (!a || !b || a == b)
		return false;

	AABB boxA = a->getAABB();
	AABB boxB = b->getAABB();

	bool overlapX = (boxA.maxX > boxB.minX) && (boxA.minX < boxB.maxX);
	bool overlapY = (boxA.maxY > boxB.minY) && (boxA.minY < boxB.maxY);

	return overlapX && overlapY;
}

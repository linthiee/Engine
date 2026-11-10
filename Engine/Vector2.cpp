#include "Vector2.h"
#include <cmath>

Vector2 BASEGAME_API Normalize(Vector2 vector)
{
	float magnitude = sqrtf(vector.x * vector.x + vector.y * vector.y);

	if (magnitude <= 0.0f)
		return Vector2(0.0f, 0.0f);

	return Vector2(vector.x / magnitude, vector.y / magnitude);
}

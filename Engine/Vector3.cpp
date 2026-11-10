#include "Vector3.h"
#include <cmath>

Vector3 Normalize(Vector3 vector)
{
	float magnitude = sqrtf(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);

	if (magnitude <= 0.0f)
		return Vector3(0.0f, 0.0f, 0.0f);

	return Vector3(vector.x / magnitude, vector.y / magnitude, vector.z / magnitude);
}


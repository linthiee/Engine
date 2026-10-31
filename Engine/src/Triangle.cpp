#include "Triangle.h"

Triangle::Triangle(Renderer* renderer) : Shape(renderer)
{
		positions =
		{
			// X,     Y,    R,    G,    B
			-0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
			 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
			 0.0f,  0.5f, 0.0f, 0.0f, 1.0f
		};

		indices = { 0, 1, 2 };

		InitBuffer();
}

#include "Square.h"

Square::Square(Renderer* renderer) : Shape(renderer)
{
	positions = 
	{
		-0.5f, -0.5f, 1.0f, 0.0f, 0.0f, // abajo izquierda
		 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, // abajo derecha
		 0.5f,  0.5f, 0.0f, 0.0f, 1.0f, // arriba derecha
		-0.5f,  0.5f, 1.0f, 1.0f, 0.0f  // arriba izquierda
	};

	indices = 
	{
		0, 1, 2,
		2, 3, 0
	};

	InitBuffer();
}
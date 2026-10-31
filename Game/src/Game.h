#pragma once
#include "BaseGame.h"
#include "Triangle.h"
#include "Square.h"

class Game : public BaseGame
{
public:
	Game();
	~Game();

	void Init() override;
	void Update() override;
	void Deinit() override;

private:

	Triangle* triangle;
	Square* square;
};
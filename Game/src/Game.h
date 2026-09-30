#pragma once
#include "BaseGame.h"
#include "Shape.h"

class Game : public BaseGame
{
public:
	Game();
	~Game();

	void Init() override;
	void Update() override;
	void Deinit() override;

private:

	Shape* shape;
	Shape* shape2;
	Shape* shape3;
};
#pragma once
#include "BaseGame.h"
#include "Triangle.h"
#include "Square.h"
#include "Sprite.h"

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
	Sprite* sprite;
	Sprite* sprite2;

	Animation* cowIdleAnim;

	Animation* idleAnim;
	Animation* walkDownAnim;
	Animation* walkUpAnim;
	Animation* walkLeftAnim;
	Animation* walkRightAnim;
};
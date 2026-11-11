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

	void InitAnimations();
	void HandlePlayerInput();
	void UpdateEntities();
	void DrawEntities();
	void CheckGameBounds(Sprite* player);

	Triangle* triangle;
	Square* square;
	Sprite* cow;
	Sprite* bunny;

	Animation* cowIdleAnim;

	Animation* idleAnim;
	Animation* walkDownAnim;
	Animation* walkUpAnim;
	Animation* walkLeftAnim;
	Animation* walkRightAnim;
};
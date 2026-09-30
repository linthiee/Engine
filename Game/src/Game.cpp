#include "Game.h"
#include "Renderer.h"

void Game::Init()
{
	float positions[] =
	{
		-0.8f, -0.5f, 1.0f, 0.0f, 0.0f,
		-0.2f, -0.5f, 0.0f, 1.0f, 0.0f,
		-0.5f,  0.5f, 0.0f, 0.0f, 1.0f
	};

	int indices[] =
	{
		0, 1, 2,
	};

	shape = new Shape(render, 3);
	shape2 = new Shape(render, 15, positions, 3, indices);

    Material* shader = new Material("res/Shaders/Basic.shader");

    shape->setMaterial(shader);
    shape2->setMaterial(shader);

	shape->InitBuffer();
	shape2->InitBuffer();

    shape->setScale(Vector2(1.0f, 1.0f));
    shape2->setScale(Vector2(1.0f, 1.0f));

    shape->setPos(Vector2(-0.5f, 0.0f));
    shape2->setPos(Vector2(0.5f, 0.0f));
}

void Game::Update()
{
    Vector2 currentRot1 = shape->getRot();
    currentRot1.x += 1.0f;
    shape->setRot(currentRot1);

    static float moveSpeed1 = 0.02f;
    Vector2 currentPos1 = shape->getPos();
    currentPos1.x += moveSpeed1;
    if (currentPos1.x > 1.5f || currentPos1.x < -1.5f)
        moveSpeed1 = -moveSpeed1;
    shape->setPos(currentPos1);

    static float scaleSpeed1 = 0.01f;
    Vector2 currentScale1 = shape->getScale();
    currentScale1.x += scaleSpeed1;
    currentScale1.y += scaleSpeed1;
    if (currentScale1.x > 2.0f || currentScale1.x < 0.5f)
        scaleSpeed1 = -scaleSpeed1;
    shape->setScale(currentScale1);

    //shape2
    Vector2 currentRot2 = shape2->getRot();
    currentRot2.x -= 2.0f;
    shape2->setRot(currentRot2);

    static float moveSpeed2 = 0.015f;
    Vector2 currentPos2 = shape2->getPos();
    currentPos2.y += moveSpeed2;
    if (currentPos2.y > 1.0f || currentPos2.y < -1.0f) 
        moveSpeed2 = -moveSpeed2;
    shape2->setPos(currentPos2);

    shape->Draw();
    shape2->Draw();
}

void Game::Deinit()
{
    shape->Destroy();
    shape2->Destroy();
}

Game::Game()
{
	shape = nullptr;
	shape2 = nullptr;
}

Game::~Game()
{
}
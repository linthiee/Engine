#include "Game.h"
#include "Renderer.h"

void Game::Init()
{
	float positions[] =
	{
		-0.8f, -0.5f, 1.0f, 0.5f, 0.2f,
		-0.2f, -0.5f, 1.0f, 0.5f, 0.2f,
		-0.5f,  0.5f, 1.0f, 0.5f, 0.2f
	};

	int indices[] =
	{
		0, 1, 2,
	};

    shape = new Shape(render, 15, positions, 3, indices);

    float positions2[] =
    {
        -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
         0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
         0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
    };
    int indices2[] =
    {
        0, 1, 2,
    };

    shape2 = new Shape(render, 15, positions2, 3, indices2);

    shape3 = new Shape(render, 15, positions2, 3, indices2);

    Material* shader = new Material("res/Shaders/Basic.shader");

    shape->setMaterial(shader);
    shape2->setMaterial(shader);
    shape3->setMaterial(shader);

	shape->InitBuffer();
	shape2->InitBuffer();
    shape3->InitBuffer();

    shape->setScale(Vector2(1.0f, 1.0f));
    shape2->setScale(Vector2(1.0f, 1.0f));
    shape3->setScale(Vector2(1.0f, 1.0f));

    shape->setPos(Vector2(0.9f, 0.0f));
    shape2->setPos(Vector2(-0.5f, 0.1f));
    shape3->setPos(Vector2(-0.5f, 0.1f));

    shape3->setRot({ -180, 0});
}

void Game::Update()
{

    Vector2 currentRot = shape->getRot();
    static float moveSpeed = 0.015f;
    Vector2 currentPos = shape->getPos();
    currentPos.y += moveSpeed;
    if (currentPos.y > 1.0f || currentPos.y < -1.0f)
    {
        moveSpeed = -moveSpeed;
        currentRot.x -= 180.0f;
        shape->setRot(currentRot);
    }
    shape->setPos(currentPos);

    shape->Draw();
    shape2->Draw();
    shape3->Draw();
}

void Game::Deinit()
{
    shape->Destroy();
    shape2->Destroy();
    shape3->Destroy();
}

Game::Game()
{
	shape = nullptr;
	shape2 = nullptr;
    shape3 = nullptr;
}

Game::~Game()
{
}
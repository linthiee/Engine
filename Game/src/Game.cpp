#include "Game.h"
#include <iostream>

void Game::Init()
{
	Material* shader = new Material("res/Shaders/BasicShader.vertex", "res/Shaders/BasicShader.fragment");

	std::cout << "Loading image textures..." << std::endl;
	Material* texShader = new Material("res/Textures/TextureShader.vertex", "res/Textures/TextureShader.fragment");

    sprite = new Sprite(render, "res/Textures/Triangle.png");
    sprite->setMaterial(texShader);

    triangle = new Triangle(render);
    square = new Square(render);

    triangle->setMaterial(shader);
    square->setMaterial(shader);
}

void Game::Update()
{
	Vector2 translation = triangle->getPos();
	translation.y += 0.01f;
	triangle->setPos(translation);

	float speed = 0.1f;
	Vector2 direction(0.0f, 0.0f);

	if (input->isKeyPressed(KEY_W))
	{
		direction.y += 1.0f;
	}
	if (input->isKeyPressed(KEY_S))
	{
		direction.y -= 1.0f;
	}
	if (input->isKeyPressed(KEY_D))
	{
		direction.x += 1.0f;
	}
	if (input->isKeyPressed(KEY_A))
	{
		direction.x -= 1.0f;
	}

	if (direction.x != 0.0f || direction.y != 0.0f)
	{
		direction = Normalize(direction);

		Vector2 currentPos = sprite->getPos();
		currentPos.x += direction.x * speed;
		currentPos.y += direction.y * speed;

		sprite->setPos(currentPos);
	}

    Vector3 rotation = square->getRot();
    rotation.z += 0.1f;
    square->setRot(rotation);

    triangle->Draw();
    square->Draw();
    sprite->Draw();
}

void Game::Deinit()
{
    triangle->Destroy();
    square->Destroy();
}

Game::Game()
{
	triangle = nullptr;
    square = nullptr;
    sprite = nullptr;
}

Game::~Game()
{
    triangle->Destroy();
    square->Destroy();
    sprite->Destroy();
}
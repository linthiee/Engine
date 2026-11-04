#include "Game.h"

void Game::Init()
{
	Material* shader = new Material("res/Shaders/BasicShader.vertex", "res/Shaders/BasicShader.fragment");
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

	Vector2 inputMove = sprite->getPos();
	if (input->isKeyPressed(KEY_W))
	{
		inputMove.y += 0.1f;
	}
	if (input->isKeyPressed(KEY_S))
	{
		inputMove.y -= 0.1f;
	}
	if (input->isKeyPressed(KEY_D))
	{
		inputMove.x += 0.1f;
	}
	if (input->isKeyPressed(KEY_A))
	{
		inputMove.x -= 0.1f;
	}
	sprite->setPos(inputMove);

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
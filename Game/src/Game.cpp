#include "Game.h"
#include "Renderer.h"
#include <iostream>

void Game::Init()
{
	float positions[] =
	{
		-0.8f, -0.5f, 1.0f, 0.0f, 0.0f,
		-0.2f, -0.5f, 0.0f, 1.0f, 0.0f,
		-0.5f,  0.5f, 0.0f, 0.0f, 1.0f
	};

	float positions2[] =
	{
		-0.3f, -0.5f, 1.0f, 0.0f, 0.0f,
		0.3f, -0.5f, 0.0f, 1.0f, 0.0f,
		0.0f,  0.5f, 0.0f, 0.0f, 1.0f
	};

	int indices[] =
	{
		0, 1, 2,
	};

	square = new Shape(render, 3);
	blueSquare = new Shape(render, 3);

	normalSquare = new Shape(render, 15, positions2, 3, indices);
	invertedSquare = new Shape(render, 15, positions2, 3, indices);

	triangle = new Shape(render, 15, positions, 3, indices);

	Material* pinkShader = new Material("res/Shaders/Pink.shader");
	Material* orangeShader = new Material("res/Shaders/Orange.shader");
	Material* blueShader = new Material("res/Shaders/Blue.shader");
	Material* redShader = new Material("res/Shaders/Red.shader");

	square->setMaterial(pinkShader);
	triangle->setMaterial(orangeShader);
	blueSquare->setMaterial(blueShader);

	normalSquare->setMaterial(redShader);
	invertedSquare->setMaterial(redShader);

	square->InitBuffer();
	triangle->InitBuffer();
	blueSquare->InitBuffer();

	normalSquare->InitBuffer();
	invertedSquare->InitBuffer();

	square->setScale(Vector2(0.5f, 0.5f));
	triangle->setScale(Vector2(1.0f, 0.5f));
	blueSquare->setScale(Vector2(0.5f, 0.5f));

	invertedSquare->setScale(Vector2(-1.0f, -0.5f));
	normalSquare->setScale(Vector2(1.0f, 0.5f));

	square->setPos(Vector2(-0.5f, 0.0f));
	triangle->setPos(Vector2(1.5f, 0.0f));
	blueSquare->setPos(Vector2(-2.2f, 1.2f));

	normalSquare->setPos(Vector2(-1.4f, 0.0f));
	invertedSquare->setPos(Vector2(-1.4f, -0.2f));

	triangle->setRot({ 0, 180 });

}

void Game::Update()
{
	//pink square
	static Vector2 squareMaxSize = { square->getScale().x * 3, square->getScale().y * 3 };
	static Vector2 squareNormalSize = { square->getScale().x, square->getScale().y };

	static float scaleSpeed = 0.01f;

	Vector2 squareCurrentScale = square->getScale();

	squareCurrentScale.x += scaleSpeed;
	squareCurrentScale.y += scaleSpeed;

	if (squareCurrentScale.x >= squareMaxSize.x || squareCurrentScale.x <= squareNormalSize.x)
		scaleSpeed = -scaleSpeed;

	square->setScale(squareCurrentScale);

	//triangle rot

	static float movespeed = 0.02f;
	Vector2 currentPos = triangle->getPos();
	currentPos.y += movespeed;

	if (currentPos.y > 1.0f || currentPos.y < -1.0f)
	{
		movespeed = -movespeed;

		Vector2 currentScale = triangle->getScale();
		currentScale.y *= -1.0f;
		triangle->setScale(currentScale);
	}
	triangle->setPos(currentPos);

	//blue square

	static int direction = 1;
	static float movespeed2 = 0.02f;

	Vector2 currentSqrPos = blueSquare->getPos();

	std::cout << "\r\r\r\r\r" << currentSqrPos.x << ", " << currentSqrPos.y;

	if (direction == 0)
		currentSqrPos.x += movespeed2;
	else if (direction == 1)
		currentSqrPos.y -= movespeed2;
	else if (direction == 2)
		currentSqrPos.x -= movespeed2;
	else if (direction == 3)
		currentSqrPos.y += movespeed2;

	if (direction == 0 && currentSqrPos.x >= 1.2f)
	{
		currentSqrPos.x = 1.2f;
		direction = 3;
	}
	else if (direction == 1 && currentSqrPos.y <= -1.2f)
	{
		currentSqrPos.y = -1.2f;
		direction = 0;
	}
	else if (direction == 2 && currentSqrPos.x <= -2.2f)
	{
		currentSqrPos.x = -2.2f;
		direction = 1;
	}
	else if (direction == 3 && currentSqrPos.y >= 1.2f)
	{
		currentSqrPos.y = 1.2f;
		direction = 2;
	}
	blueSquare->setPos(currentSqrPos);

	static float initialRot = 0.02f;
	float maxRot = 3.0f;

	Vector2 rotNormal = normalSquare->getRot();

	square->Draw();
	triangle->Draw();
	blueSquare->Draw();
	normalSquare->Draw();
	invertedSquare->Draw();
}

void Game::Deinit()
{
	square->Destroy();
	triangle->Destroy();
	blueSquare->Destroy();
	normalSquare->Destroy();
	invertedSquare->Destroy();
}

Game::Game()
{
	square = nullptr;
	triangle = nullptr;
	blueSquare = nullptr;
	normalSquare = nullptr;
	invertedSquare = nullptr;
}

Game::~Game()
{
}
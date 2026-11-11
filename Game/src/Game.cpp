#include "Timer.h"
#include "Game.h"
#include <cmath>
#include <iostream>

void Game::Init()
{
	Material* shader = new Material("res/Shaders/BasicShader.vertex", "res/Shaders/BasicShader.fragment");
	Material* texShader = new Material("res/Textures/TextureShader.vertex", "res/Textures/TextureShader.fragment");

    cow = new Sprite(render, "res/Textures/Cow Spritesheet.png");
    bunny = new Sprite(render, "res/Textures/Bunny Spritesheet.png");

    cow->setMaterial(texShader);
    bunny->setMaterial(texShader);

	triangle = new Triangle(render);
	square = new Square(render);

	triangle->setMaterial(shader);
	square->setMaterial(shader);

	bunny->setScale(Vector2(bunny->getScale().x * 2.0f, bunny->getScale().y * 2.0f));

	InitAnimations();
}

void Game::Update()
{
	HandlePlayerInput();
	UpdateEntities();
	DrawEntities();
}

void Game::Deinit()
{
    triangle->Destroy();
    square->Destroy();
}

void Game::InitAnimations()
{
	float cowTexW = cow->GetTextureWidth();
	float cowTexH = cow->GetTextureHeight();

	float cowFrameW = cowTexW / 3.0f;
	float cowFrameH = cowTexH / 2.0f;

	float texW = bunny->GetTextureWidth();
	float texH = bunny->GetTextureHeight();

	float frameW = texW / 4.0f;
	float frameH = texH / 4.0f;
	float duration = 0.8f;

	cowIdleAnim = new Animation();
	cowIdleAnim->AddFrame(0.0f, cowFrameH * 1.0f, cowFrameW, cowFrameH, cowTexW, cowTexH, duration, 2);

	idleAnim = new Animation();
	idleAnim->AddFrame(0.0f, frameH * 3.0f, frameW, frameH, texW, texH, duration, 2);

	walkDownAnim = new Animation();
	walkDownAnim->AddFrame(frameW * 2.0f, frameH * 3.0f, frameW, frameH, texW, texH, duration, 2);

	walkUpAnim = new Animation();
	walkUpAnim->AddFrame(0.0f, frameH * 2.0f, frameW, frameH, texW, texH, duration, 4);

	walkLeftAnim = new Animation();
	walkLeftAnim->AddFrame(0.0f, frameH * 1.0f, frameW, frameH, texW, texH, duration, 4);

	walkRightAnim = new Animation();
	walkRightAnim->AddFrame(0.0f, 0.0f, frameW, frameH, texW, texH, duration, 4);

	bunny->SetAnimation(walkDownAnim);
	cow->SetAnimation(cowIdleAnim);
}

void Game::HandlePlayerInput()
{
	if (input->isMouseButtonPressed(MOUSE_BUTTON_LEFT))
		std::cout << "X: " << input->getMousePos().x << " Y: " << input->getMousePos().y << "\r\r\r";

	std::cout << cow->getPos().x - (cow->GetTextureWidth() / 4.0f) << "\r\r\r";

	Vector2 translation = triangle->getPos();
	translation.y += 0.01f;
	triangle->setPos(translation);

	float speed = 0.05f;
	Vector2 direction(0.0f, 0.0f);

	if (input->isKeyPressed(KEY_W))
	{
		direction.y += 1.0f;
		bunny->SetAnimation(walkUpAnim);
	}
	if (input->isKeyPressed(KEY_S))
	{
		direction.y -= 1.0f;
		bunny->SetAnimation(walkDownAnim);
	}
	if (input->isKeyPressed(KEY_D))
	{
		direction.x += 1.0f;
		bunny->SetAnimation(walkRightAnim);
	}
	if (input->isKeyPressed(KEY_A))
	{
		direction.x -= 1.0f;
		bunny->SetAnimation(walkLeftAnim);
	}

	if (direction.x != 0.0f || direction.y != 0.0f)
	{
		direction = Normalize(direction);

		Vector2 currentPos = bunny->getPos();
		currentPos.x += direction.x * speed;
		currentPos.y += direction.y * speed;

		bunny->setPos(currentPos);
		CheckGameBounds(bunny);
	}
	else
		bunny->SetAnimation(idleAnim);
}

void Game::UpdateEntities()
{
	Vector3 rotation = square->getRot();
	rotation.z += 0.1f;
	square->setRot(rotation);

	bunny->UpdateAnimation(timer);
	cow->UpdateAnimation(timer);
}

void Game::DrawEntities()
{
	triangle->Draw();
	square->Draw();
	cow->Draw();
	bunny->Draw();
}

void Game::CheckGameBounds(Sprite* player)
{
	float orthoY = 5.0f;
	float orthoX = orthoY * (900.0f / 800.0f);

	float halfWidth = player->getScale().x * 0.15f;
	float halfHeight = player->getScale().y * 0.15f;

	Vector2 pos = player->getPos();

	//derecha e izquierda
	if (pos.x + halfWidth > orthoX)
		pos.x = orthoX - halfWidth;
	else if (pos.x - halfWidth < -orthoX)
		pos.x = -orthoX + halfWidth;

	//arriba y abajo
	if (pos.y + halfHeight > orthoY)
		pos.y = orthoY - halfHeight;
	else if (pos.y - halfHeight < -orthoY)
		pos.y = -orthoY + halfHeight;

	player->setPos(pos);
}

Game::Game()
{
	triangle = nullptr;
    square = nullptr;
    cow = nullptr;
    bunny = nullptr;
}

Game::~Game()
{
    triangle->Destroy();
    square->Destroy();
    cow->Destroy();
    bunny->Destroy();
}
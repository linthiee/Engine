#include "Timer.h"
#include "Timer.h"
#include "Game.h"
#include <cmath>

static void Movement(float speed);

void Game::Init()
{
	Material* shader = new Material("res/Shaders/BasicShader.vertex", "res/Shaders/BasicShader.fragment");
	Material* texShader = new Material("res/Textures/TextureShader.vertex", "res/Textures/TextureShader.fragment");

    bunny = new Sprite(render, "res/Textures/Cow Spritesheet.png");
    cow = new Sprite(render, "res/Textures/Bunny Spritesheet.png");

    bunny->setMaterial(texShader);
    cow->setMaterial(texShader);

	float cowTexW = bunny->GetTextureWidth();
	float cowTexH = bunny->GetTextureHeight();

	float cowFrameW = cowTexW / 3.0f;
	float cowFrameH = cowTexH / 2.0f;

	float texW = cow->GetTextureWidth();
	float texH = cow->GetTextureHeight();

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

	cow->SetAnimation(walkDownAnim);
	bunny->SetAnimation(cowIdleAnim);

    triangle = new Triangle(render);
    square = new Square(render);

    triangle->setMaterial(shader);
    square->setMaterial(shader);

	cow->setScale(Vector2(cow->getScale().x * 2.0f, cow->getScale().y * 2.0f));
}

void Game::Update()
{
	Vector2 translation = triangle->getPos();
	translation.y += 0.01f;
	triangle->setPos(translation);

	float speed = 0.05f;
	Vector2 direction(0.0f, 0.0f);

	if (input->isKeyPressed(KEY_W))
	{
		direction.y += 1.0f;
		cow->SetAnimation(walkUpAnim);
	}
	if (input->isKeyPressed(KEY_S))
	{
		direction.y -= 1.0f;
		cow->SetAnimation(walkDownAnim);
	}
	if (input->isKeyPressed(KEY_D))
	{
		direction.x += 1.0f;
		cow->SetAnimation(walkRightAnim);
	}
	if (input->isKeyPressed(KEY_A))
	{
		direction.x -= 1.0f;
		cow->SetAnimation(walkLeftAnim);
	}

	if (direction.x != 0.0f || direction.y != 0.0f)
	{
		direction = Normalize(direction);

		Vector2 currentPos = cow->getPos();
		currentPos.x += direction.x * speed;
		currentPos.y += direction.y * speed;

		cow->setPos(currentPos);
	}
	else
		cow->SetAnimation(idleAnim);

    Vector3 rotation = square->getRot();
    rotation.z += 0.1f;
    square->setRot(rotation);

	cow->UpdateAnimation(timer);
	bunny->UpdateAnimation(timer);

    triangle->Draw();
    square->Draw();
    bunny->Draw();
	cow->Draw();
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
    bunny = nullptr;
    cow = nullptr;
}

Game::~Game()
{
    triangle->Destroy();
    square->Destroy();
    bunny->Destroy();
    cow->Destroy();
}

void Movement(float speed)
{
}

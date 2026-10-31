#include "Game.h"
#include "Renderer.h"
#include <iostream>

void Game::Init()
{
    Material* shader = new Material("res/Shaders/BasicShader.vertex", "res/Shaders/BasicShader.fragment");

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
    
    Vector3 rotation = square->getRot();
    rotation.z += 0.1f;
    square->setRot(rotation);

    triangle->Draw();
    square->Draw();
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
}

Game::~Game()
{
    triangle->Destroy();
    square->Destroy();
}
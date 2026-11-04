#include "Game.h"
#include <iostream>

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
    
    if (input->isKeyPressed(KEY_SPACE))
    {
        std::cout << "Apretando Space" << std::endl;
    }

    if (input->isMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        std::cout << "Boton left" << std::endl;
        std::cout << "X:" << input->getMousePos().x << "Y:" << input->getMousePos().y << std::endl;
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
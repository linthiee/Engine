#include "BaseGame.h"
#include "Shape.h"

BaseGame::BaseGame()
{
	window = new Window();
	render = new Renderer();
	material = new Material();
}

BaseGame::~BaseGame()
{
	delete render;
	delete window;
	delete material;
}

void BaseGame::EngineInit(const int width, const int height, const char* name)
{
	if (!window->Init())
	{
		return;
	}

	window->CreateWindow(width, height, name);

	Init();
}

void BaseGame::Run()
{
	/* Loop until the user closes the window */
	while (!window->WindowShouldClose())
	{
		/* Render here */
		render->Render();
		Update();

		/* Swap front and back buffers */
		window->SwapBuffers();

		/* Poll for and process events */
		window->Events();
	}

	Deinit();
}
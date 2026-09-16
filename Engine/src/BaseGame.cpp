#include "BaseGame.h"
#include "Shape.h"

BaseGame::BaseGame()
{
	window = new Window();
	render = new Renderer(window);
}

BaseGame::~BaseGame()
{
	delete render;
	delete window;
}

void BaseGame::EngineInit(const int width, const int height, const char* name)
{
	if (!window->Init())
	{
		return;
	}

	window->CreateWindow(width, height, name);

	render->InitShaders();

	Init();
}

void BaseGame::Run()
{
	/* Loop until the user closes the window */
	while (!window->WindowShouldClose())
	{
		/* Swap front and back buffers */
		window->SwapBuffers();

		/* Render here */
		render->Render();
		Update();

		/* Poll for and process events */
		window->Events();
	}

	Deinit();
}
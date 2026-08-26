#include "BaseGame.h"

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

void BaseGame::Run()
{
	if (!window->Init())
	{
		return;
	}

	window->CreateWindow(600, 250, "BaseGame");
	/* Loop until the user closes the window */
	while (!window->WindowShouldClose())
	{
		/* Swap front and back buffers */
		window->SwapBuffers();

		/* Render here */
		render->Render();

		/* Poll for and process events */
		window->Events();
	}
}
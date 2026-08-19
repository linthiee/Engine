#include "BaseGame.h"

BaseGame::BaseGame()
{
	window = new Window();
	render = new Renderer(window);
}

BaseGame::~BaseGame()
{
	delete window;
	delete render;
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
		/* Render here */
		render->Render();

		/* Swap front and back buffers */
		window->SwapBuffers();

		/* Poll for and process events */
		window->Events();
	}
}
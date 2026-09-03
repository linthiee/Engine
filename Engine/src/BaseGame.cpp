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

void BaseGame::Run()
{
	Shape shape = Shape(render, 3);

	if (!window->Init())
	{
		return;
	}

	window->CreateWindow(600, 250, "BaseGame");

	render->InitShaders();

	shape.InitBuffer();
	/* Loop until the user closes the window */
	while (!window->WindowShouldClose())
	{
		/* Swap front and back buffers */
		window->SwapBuffers();

		/* Render here */
		render->Render();
		shape.Draw();
		/* Poll for and process events */
		window->Events();
	}
}
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

void BaseGame::EngineInit(const int width, const int height, const char* name, std::string& shader)
{
	if (!window->Init())
	{
		return;
	}

	window->CreateWindow(width, height, name);

	render->InitShaders(shader);

	Init();
}

void BaseGame::Run()
{
	render->SetUniformMat4f("u_MVP", render->getMVPMatrix4x4());
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
#include "BaseGame.h"
#include "Shape.h"

BaseGame::BaseGame()
{
	window = new Window();
	render = new Renderer();
	input = new Input(window);
	timer = new Timer();
	collisionManager = new CollisionManager();
}

BaseGame::~BaseGame()
{
	delete input;
	delete render;
	delete window;
	delete timer;
	delete collisionManager;
}

void BaseGame::EngineInit(const int width, const int height, const char* name)
{
	if (!window->Init())
	{
		return;
	}

	window->CreateWindow(width, height, name);
	render->Init(width, height);

	Init();
}

void BaseGame::Run()
{
	/* Loop until the user closes the window */
	while (!window->WindowShouldClose())
	{
		timer->Update();
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
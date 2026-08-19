#pragma once

#ifdef BASEGAME_EXPORTS
#define BASEGAME_API __declspec(dllexport)
#else
#define BASEGAME_API __declspec(dllimport)
#endif

#include "Window.h"
#include "Renderer.h"

class /*BASEGAME_API*/ BaseGame
{
private:
	Window* window;
	Renderer* render;

public:
	BaseGame();
	~BaseGame();

	void Run();
};


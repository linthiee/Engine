#pragma once

#include "Export.h"
#include "Window.h"
#include "Renderer.h"

class BASEGAME_API BaseGame
{
protected:
	Window* window;
	Renderer* render;

public:
	BaseGame();
	~BaseGame();

	void EngineInit(const int width, const int height, const char* name);

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Deinit() = 0;

	void Run();

};


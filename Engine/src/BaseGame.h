#pragma once

#include "Export.h"
#include "Window.h"
#include "Renderer.h"
#include "Material.h"
#include "Input.h"

class BASEGAME_API BaseGame
{
protected:
	Window* window;
	Renderer* render;
	Input* input;

public:
	BaseGame();
	~BaseGame();

	void EngineInit(const int width, const int height, const char* name);

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Deinit() = 0;

	void Run();

};


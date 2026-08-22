#pragma once
#include "Window.h"

class Renderer
{
private:
	Window* renderWindow;

public:
	Renderer(Window* window);
		
	void Render();
	void DrawTriangle();
};


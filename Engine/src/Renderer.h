#pragma once
#include "Window.h"

class Renderer
{
private:
	Window* renderWindow;
	unsigned int buffer;

public:
	Renderer(Window* window);
		
	void Render();
	void DrawTriangle();
};


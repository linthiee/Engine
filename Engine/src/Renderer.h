#pragma once
#include "Window.h"
#include <vector>

class Renderer
{
private:
	Window* renderWindow;
	
public:
	Renderer(Window* window);
	
	void Render();
	void Draw(int vertexCount);
};


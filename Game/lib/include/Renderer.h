#pragma once
#include "Window.h"
#include <vector>

class Renderer
{
private:
	Window* renderWindow;

	unsigned int vertexShader;
	unsigned int fragmentShader;
	unsigned int shaderProgram;

public:
	Renderer(Window* window);
	
	void InitShaders();
	void Render();
	void Draw(int vertexCount);
};


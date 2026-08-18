#pragma once
#include <GLFW/glfw3.h>

class BaseGame
{
private:
	GLFWwindow* window;
	bool runing;

public:
	BaseGame();
	~BaseGame();
	bool InIt();
	void CreateWindow(int width, int height, const char* title);
	bool WindowShouldClose();
	void Render();
	void SwapBuffers();
	virtual void Run();
};


#pragma once
#include <GLFW/glfw3.h>

class Window
{
private:
	GLFWwindow* window;

public:
	Window();
	~Window();

	bool Init();
	void CreateWindow(int width, int height, const char* title);
	bool WindowShouldClose();
	void SwapBuffers();
	void Events();
};


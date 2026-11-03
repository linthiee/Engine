#pragma once

struct GLFWwindow;

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
	GLFWwindow* GetWindow();
};


#pragma once

#ifdef BASEGAME_EXPORTS
#define BASEGAME_API __declspec(dllexport)
#else
#define BASEGAME_API __declspec(dllimport)
#endif

#include <GLFW/glfw3.h>

class BASEGAME_API BaseGame
{
private:
	GLFWwindow* window;

public:
	BaseGame();
	~BaseGame();
	bool InIt();
	void CreateWindow(int width, int height, const char* title);
	bool WindowShouldClose();
	void Render();
	void SwapBuffers();
	void Events();
	virtual void Run();
};


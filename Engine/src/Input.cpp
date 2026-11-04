#include "Input.h"
#include "GLFW/glfw3.h"
#include "Window.h"

Input::~Input()
{
}

Input::Input(Window* window)
{
	this->window = window;
}


bool Input::isKeyPressed(Key key)
{
	int state = glfwGetKey(window->GetWindow(), key);

	return state == GLFW_PRESS || state == GLFW_REPEAT;
}

bool Input::isKeyUp(Key key)
{
	int state = glfwGetKey(window->GetWindow(), key);

	return state == GLFW_RELEASE;
}




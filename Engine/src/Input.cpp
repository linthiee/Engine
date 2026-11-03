#include "Input.h"
#include "GLFW/glfw3.h"

Input::~Input()
{
}

Input::Input()
{
	
}


bool Input::isKeyPressed(Key key)
{
	int state = glfwGetKey(window, key);

	return state == GLFW_PRESS || state == GLFW_REPEAT;
}

bool Input::isKeyUp(Key key)
{
	int state = glfwGetKey(window, key);

	return state == GLFW_RELEASE;
}

void Input::SetWindow(GLFWwindow* window)
{
	this->window = window;
}



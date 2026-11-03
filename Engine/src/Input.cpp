#include "Input.h"


Input::~Input()
{
}

Input::Input(GLFWwindow* window)
{
	this->window = window;
	currentState.resize(GLFW_KEY_LAST + 1, false);
	previousState.resize(GLFW_KEY_LAST + 1, false);
}


void Input::Update()
{

	previousState = currentState;

	for (int key = 0; key <= GLFW_KEY_LAST; ++key) 
	{
		currentState[key] = (glfwGetKey(window, key) == GLFW_PRESS);
	}
}


bool Input::isKeyPressed(keys key)
{
	return glfwSetKeyCallback(window, key_callback);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_E && action == GLFW_PRESS);
}

bool Input::isKeyDown(keys key)
{
	return currentState[key] && !previousState[key];
}

bool Input::isKeyRelease(keys key)
{
	return !currentState[key] && previousState[key];
}
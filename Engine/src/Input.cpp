#include "Input.h"
#include "GLFW/glfw3.h"
#include "Window.h"
#include "Vector2.h"

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


bool Input::isMouseButtonPressed(Mouse_Buttons mouseButton)
{
	int state = glfwGetMouseButton(window->GetWindow(), mouseButton);

	return state == GLFW_PRESS;
}

Vector2 Input::getMousePos()
{
	double xpos;
	double ypos;

	glfwGetCursorPos(window->GetWindow(), &xpos, &ypos);
	return Vector2( (float)xpos, (float)ypos);
}






#include "GL/glew.h"
#include "Window.h"

Window::Window()
{
    this->window = nullptr;
}

Window::~Window()
{
    glfwTerminate();
}

bool Window::Init()
{
    if (!glfwInit())
    {
        glfwTerminate();
        return false;
    }
    return true;
}

void Window::CreateWindow(int width, int height, const char* title)
{
    window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(window);
    glewInit();
}

bool Window::WindowShouldClose()
{
    return glfwWindowShouldClose(window);
}

void Window::SwapBuffers()
{
    glfwSwapBuffers(window);
}

void Window::Events()
{
    glfwPollEvents();
}


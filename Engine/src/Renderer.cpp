#include "Renderer.h"
#include <GLFW/glfw3.h>

Renderer::Renderer(Window* window)
{
    renderWindow = window;
}

void Renderer::Render()
{
    glClear(GL_COLOR_BUFFER_BIT);
}
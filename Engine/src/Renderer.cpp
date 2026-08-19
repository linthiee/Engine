#include "Renderer.h"
#include <GLFW/glfw3.h>

Renderer::Renderer(Window* window)
{
    renderWindow = window;
}

void Renderer::Render()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLES);
    glVertex2d(-0.5f, -0.5f);
    glVertex2d(0.0f, 0.5f);
    glVertex2d(0.5f, -0.5f);
    glEnd();
}
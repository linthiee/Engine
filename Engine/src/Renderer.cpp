#include "GL/glew.h"
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

void Renderer::DrawTriangle()
{
    unsigned int buffer;
    float positions[6] =
    {
       -0.5f, -0.5f,
        0.0f,  0.5f,
        0.5f, -0.5f
    };
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

    glDrawArrays(GL_TRIANGLES, 0, 3);
}
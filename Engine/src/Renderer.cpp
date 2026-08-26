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

void Renderer::Draw(int vertexCount)
{
	glDrawArrays(GL_TRIANGLES, 0, vertexCount);
}
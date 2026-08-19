#include "BaseGame.h"

BaseGame::BaseGame()
{
    window = nullptr;
}

BaseGame::~BaseGame()
{
    glfwTerminate();
}

bool BaseGame::InIt()
{
    if (!glfwInit())
    {
        glfwTerminate();
        return false;
    }
    return true;
}

void BaseGame::CreateWindow(int width, int height, const char* title)
{
    window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(window);
}

bool BaseGame::WindowShouldClose()
{
    return glfwWindowShouldClose(window);
}

void BaseGame::Render()
{
    glClear(GL_COLOR_BUFFER_BIT);
}

void BaseGame::SwapBuffers()
{
    glfwSwapBuffers(window);
}

void BaseGame::Events()
{
    glfwPollEvents();
}

void BaseGame::Run()
{
    if (!InIt())
    {
        return;
    }

    CreateWindow(600, 250, "BaseGame");
    /* Loop until the user closes the window */
    while (!WindowShouldClose())
    {
        /* Render here */
        Render();

        /* Swap front and back buffers */
        SwapBuffers();

        /* Poll for and process events */
        Events();
    }
}
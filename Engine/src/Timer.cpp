#include "Timer.h"
#include <GLFW/glfw3.h>

Timer::Timer()
{
	lastFrameTime = static_cast<float>(glfwGetTime()) * 1000.0f;
	deltaTimeMs = 0.0f;
}

Timer::~Timer()
{
}

void Timer::Update()
{
	float currentTime = static_cast<float>(glfwGetTime()) * 1000.0f;
	deltaTimeMs = currentTime - lastFrameTime;
	lastFrameTime = currentTime;
}

float Timer::timeBetweenFrames() const
{
	return deltaTimeMs;
}
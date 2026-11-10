#pragma once
#include "Export.h"

class BASEGAME_API Timer
{
private:
	float lastFrameTime = 0.0f;
	float deltaTimeMs = 0.0f;

public:
	Timer();
	~Timer();

	void Update();
	float timeBetweenFrames() const;
};

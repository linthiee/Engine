#pragma once
#include "Export.h"
#include "Frame.h"
#include "Timer.h"
#include <vector>

class BASEGAME_API Animation
{
public:
	Animation();
	~Animation();

	void Update(Timer& timer);

	void AddFrame(float frameX, float frameY,
		float frameWidth, float frameHeigth,
		float textureWidth, float textureHeigth,
		float durationInSecs);

	void AddFrame(float frameX, float frameY,
		float frameWidth, float frameHeigth,
		float textureWidth, float textureHeigth,
		float durationInSecs,
		int frameCount);

	int CurrentFrame();

	std::vector<Frame>& GetFrames();

private:
	float _currentFrame, _currentTime;
	float _length;
	std::vector<Frame> _frames;
};
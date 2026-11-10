#pragma once
struct UVCoords
{
	float u;
	float v;
};

class Frame
{
public:
	Frame();
	~Frame();
	UVCoords uvCoords[4];
};

#pragma once
#include "Renderer.h"

class BASEGAME_API TextureImporter
{
private:
	unsigned int renderID;
	std::string filepath;
	unsigned char* localBuffer;

	int width;
	int height;
	int bitsPerPixel;

public:
	TextureImporter();
	TextureImporter(const char* filepath);
	~TextureImporter();

	void ImportTexture(const char* filepath);

	void Bind(unsigned int slot = 0) const;
	void Unbind();

	int GetWidth() const;
	int GetHeight() const;
};
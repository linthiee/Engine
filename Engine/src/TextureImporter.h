#pragma once
#include "Renderer.h"

class TextureImporter
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
	~TextureImporter();

	void ImportTexture(const char* filepath);

	void Bind() const;
	void Unbind();

	int GetWidth() const;
	int GetHeight() const;
};
#include "GL/glew.h"
#include "TextureImporter.h"
#include "stb_image.h"
#include <iostream>

TextureImporter::TextureImporter()
{
	renderID = 0;

	localBuffer = nullptr;

	width = 0;
	height = 0;
	bitsPerPixel = 0;
}

TextureImporter::TextureImporter(const char* filepath)
{
	renderID = 0;

	localBuffer = nullptr;

	width = 0;
	height = 0;
	bitsPerPixel = 0;

	ImportTexture(filepath);
}

TextureImporter::~TextureImporter()
{
	glDeleteTextures(1, &renderID);
}

void TextureImporter::ImportTexture(const char* filepath)
{
	this->filepath = filepath;

	stbi_set_flip_vertically_on_load(1);
	localBuffer = stbi_load(filepath, &width, &height, &bitsPerPixel, 4);

	glGenTextures(1, &renderID);
	glBindTexture(GL_TEXTURE_2D, renderID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, localBuffer);

	glBindTexture(GL_TEXTURE_2D, 0);

	if (localBuffer)
		stbi_image_free(localBuffer);

	std::cout << "Succes!" << std::endl;
}

void TextureImporter::Bind(unsigned int slot) const
{
	glActiveTexture(GL_TEXTURE0 + slot);
	glBindTexture(GL_TEXTURE_2D, renderID);
}

void TextureImporter::Unbind()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

int TextureImporter::GetWidth() const
{
	return width;
}

int TextureImporter::GetHeight() const
{
	return height;
}
#pragma once
#include "Export.h"
#include "Entity2D.h"
#include "TextureImporter.h"
#include <vector>

class BASEGAME_API Sprite : public Entity2D
{
private:
	std::vector<float> positions;
	std::vector<unsigned int> indices;

	unsigned int vao = 0;
	unsigned int vbo = 0;
	unsigned int ibo = 0;

	TextureImporter* importer;

public:
	Sprite(Renderer* renderer, const char* texturePath);
	virtual ~Sprite();

	void InitBuffer();
	void Draw();
	void Destroy();
};
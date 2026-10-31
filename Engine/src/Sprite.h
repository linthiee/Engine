#pragma once
#include "TextureImporter.h"
#include "Entity2D.h"

class Sprite : public Entity2D
{
public:
	Sprite();
	~Sprite();

	TextureImporter* importer;

	void Draw();
};


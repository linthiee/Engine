#pragma once
#include "Export.h"
#include "Entity2D.h"
#include "TextureImporter.h"
#include "Animation.h"
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
	Animation* animation;

public:
	Sprite(Renderer* renderer, const char* texturePath);
	virtual ~Sprite();

	void SetAnimation(Animation* animation);
	void UpdateAnimation(Timer* timer);
	void SetUVs(Frame& frame);

	inline float GetTextureWidth() const { return importer ? static_cast<float>(importer->GetWidth()) : 0.0f; }
	inline float GetTextureHeight() const { return importer ? static_cast<float>(importer->GetHeight()) : 0.0f; }

	void InitBuffer();
	void Draw();
	void Destroy();
};
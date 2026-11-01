#include "Sprite.h"

Sprite::Sprite(Renderer* renderer, const char* texturePath) : Entity2D(renderer)
{
	importer = new TextureImporter(texturePath);

	positions =
	{
		// X,     Y,     R,    G,    B,    U,    V
		-0.5f, -0.5f,  1.0f, 1.0f, 1.0f,  0.0f, 0.0f, 
		 0.5f, -0.5f,  1.0f, 1.0f, 1.0f,  1.0f, 0.0f, 
		 0.5f,  0.5f,  1.0f, 1.0f, 1.0f,  1.0f, 1.0f, 
		-0.5f,  0.5f,  1.0f, 1.0f, 1.0f,  0.0f, 1.0f  
	};

	indices =
	{
		0, 1, 2,
		2, 3, 0
	};

	InitBuffer();
}

Sprite::~Sprite()
{
	Destroy();
}

void Sprite::InitBuffer()
{
	renderer->InitBuffers(positions.data(), positions.size() * sizeof(float), indices.data(), indices.size() * sizeof(unsigned int), vao, vbo, ibo);
}

void Sprite::Draw()
{
	if (!material || !importer) 
		return;

	importer->Bind(0);
	material->SetUniform1i("u_Texture", 0);

	renderer->BindVAO(vao);
	Entity2D::Draw(indices.size());
}

void Sprite::Destroy()
{
	if (vao != 0)
	{
		renderer->DeleteBuffers(vao, vbo, ibo);
		vao = 0;
	}
	if (importer)
	{
		delete importer;
		importer = nullptr;
	}
	positions.clear();
	indices.clear();
}
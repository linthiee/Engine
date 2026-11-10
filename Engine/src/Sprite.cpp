#include "Sprite.h"

Sprite::Sprite(Renderer* renderer, const char* texturePath) : Entity2D(renderer)
{
	importer = new TextureImporter(texturePath);
	animation = nullptr;

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

void Sprite::SetAnimation(Animation* animation)
{
	if (this->animation == animation)
		return;

	this->animation = animation;
	if (animation && !animation->GetFrames().empty())
		SetUVs(animation->GetFrames()[0]);
}

void Sprite::UpdateAnimation(Timer* timer)
{
	if (!animation || animation->GetFrames().empty())
		return;

	animation->Update(*timer);
	int currentFrame = animation->CurrentFrame();
	SetUVs(animation->GetFrames()[currentFrame]);
}

void Sprite::SetUVs(Frame& frame)
{
	//abajo izquierda
	positions[5] = frame.uvCoords[0].u;
	positions[6] = frame.uvCoords[0].v;

	//abajo derecha
	positions[12] = frame.uvCoords[1].u;
	positions[13] = frame.uvCoords[1].v;

	//arriba derecha
	positions[19] = frame.uvCoords[3].u;
	positions[20] = frame.uvCoords[3].v;

	//arriba izquierda
	positions[26] = frame.uvCoords[2].u;
	positions[27] = frame.uvCoords[2].v;

	renderer->UpdateVBO(vbo, positions.data(), positions.size() * sizeof(float));
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
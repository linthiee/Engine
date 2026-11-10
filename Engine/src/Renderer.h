#pragma once
#include "Window.h"
#include "Material.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

class Renderer
{
private:
	glm::mat4x4 projection;
	glm::mat4x4 view;

	float aspectRatio;

public:
	Renderer();
	
	void Init(const int width, const int height);
	void Render();
	void Draw(int indices);

	void UpdateVBO(unsigned int vbo, const float* positions, int posSizeInBytes);

	//void InitSpriteBuffers(const float* positions, int posSizeInBytes, const unsigned int* indices, int indicesSizeInBytes, unsigned int& vao, unsigned int& vbo, unsigned int& ibo);
	void InitBuffers(const float* positions, int posSizeInBytes, const unsigned int* indices, int indicesSizeInBytes, unsigned int& vao, unsigned int& vbo, unsigned int& ibo);
	void BindVAO(unsigned int vao);
	void DeleteBuffers(unsigned int& vao, unsigned int& vbo, unsigned int& ibo);

	glm::mat4x4 getProjectionMat4x4() const;
	glm::mat4x4 getViewMat4x4() const;
};


#pragma once
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <stb/stb_image.h>

#include "ShaderClass.h"

struct Texture
{
	unsigned int ID;
	GLenum type;

	Texture() = default;
	Texture(const char* Path);
	void CreateTexture(const char* Path);
	void TextureUnit(Shader& shader, const char* uniform);
	void Bind();
	void Unbind();
	void Delete();
};
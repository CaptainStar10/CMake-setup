#include "core/Texture.h"

Texture::Texture(const char* Path)
{
	this->type = GL_TEXTURE_2D;

	int width, height, channels;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* Pixels = stbi_load(Path, &width, &height, &channels, 0);

	glGenTextures(1, &ID);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(type, ID);

	glTexParameteri(type, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(type, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(type, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(type, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexImage2D(type, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, Pixels);
	glGenerateMipmap(type);

	stbi_image_free(Pixels);
}

void Texture::CreateTexture(const char* Path)
{
	this->type = GL_TEXTURE_2D;

	int width, height, channels;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* Pixels = stbi_load(Path, &width, &height, &channels, 0);

	glGenTextures(1, &ID);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(type, ID);

	glTexParameteri(type, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(type, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(type, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(type, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexImage2D(type, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, Pixels);
	glGenerateMipmap(type);

	stbi_image_free(Pixels);
}
void Texture::TextureUnit(Shader& shader, const char* uniform)
{
	unsigned int texImage = glGetUniformLocation(shader.ID, uniform);
	shader.Activate();
}
void Texture::Bind()
{
	glBindTexture(type, ID);
}
void Texture::Unbind()
{
	glBindTexture(type, 0);
}
void Texture::Delete()
{
	glDeleteTextures(1, &ID);
}
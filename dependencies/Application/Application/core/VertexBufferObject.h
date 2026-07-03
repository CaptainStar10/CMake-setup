#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <vector>

struct Vertex
{
	glm::vec3 Position;
	glm::vec3 Colour;
	glm::vec2 TextureCoordintaes;
};

struct VertexBufferObject
{
	unsigned int ID;
	VertexBufferObject(GLsizeiptr size, GLfloat* vertices);
	VertexBufferObject(std::vector<Vertex>& vertices);
	void Bind();
	void Unbind();
	void Delete();
};

#pragma once
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <vector>

struct ElementBufferObject
{
	unsigned int ID;
	ElementBufferObject(GLsizeiptr size, GLuint* indices);
	ElementBufferObject(std::vector<GLuint>& indices);
	void Bind();
	void Unbind();
	void Delete();
};
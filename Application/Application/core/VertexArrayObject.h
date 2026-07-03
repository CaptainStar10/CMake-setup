#pragma once
#include "VertexBufferObject.h"

struct VertexArrayObject
{
	unsigned int ID;
	VertexArrayObject();
	void Link(VertexBufferObject& VBO, GLint layout, GLint numComponents, GLenum type, GLsizei stride, void* offset);
	void Bind();
	void Unbind();
	void Delete();
};
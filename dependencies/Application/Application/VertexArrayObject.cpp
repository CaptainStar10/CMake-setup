#include "core/VertexArrayObject.h"

VertexArrayObject::VertexArrayObject()
{
	glGenVertexArrays(1, &ID);
}
void VertexArrayObject::Link(VertexBufferObject& VBO, GLint layout, GLint numComponents, GLenum type, GLsizei stride, void* offset)
{
	VBO.Bind();

	glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
	glEnableVertexAttribArray(layout);

	VBO.Unbind();
}
void VertexArrayObject::Bind()
{
	glBindVertexArray(ID);
}
void VertexArrayObject::Unbind()
{
	glBindVertexArray(ID);
}
void VertexArrayObject::Delete()
{
	glDeleteVertexArrays(1, &ID);
}
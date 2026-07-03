#pragma once
#include "VertexArrayObject.h"
#include "VertexBufferObject.h"
#include "ElementBufferObject.h"
#include "ShaderClass.h"
#include "Texture.h"

struct Mesh
{
	std::vector<Vertex> MeshVertices = {};
	std::vector<GLuint> MeshIndices = {};
	std::vector<Texture> MeshTexture = {};

	VertexArrayObject VAO;

	Mesh(std::vector<Vertex>& MeshVertices, std::vector<GLuint>& MeshIndices, std::vector<Texture>& MeshTexture);
	void RenderMesh(Shader& shader);
	~Mesh();
};
#include "core/Mesh.h"

Mesh::Mesh(std::vector<Vertex>& MeshVertices, std::vector<GLuint>& MeshIndices, std::vector<Texture>& MeshTexture)
{
	this->MeshVertices = MeshVertices;
	this->MeshIndices = MeshIndices;
	this->MeshTexture = MeshTexture;

	this->VAO.Bind();
	VertexBufferObject VBO(MeshVertices);
	VBO.Bind();
	ElementBufferObject EBO(MeshIndices);
	EBO.Bind();

	this->VAO.Link(VBO, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)(0 * sizeof(float)));
	this->VAO.Link(VBO, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	this->VAO.Link(VBO, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));

	VBO.Unbind();
	this->VAO.Unbind();
}

void Mesh::RenderMesh(Shader& shader)
{
	shader.Activate();
	VAO.Bind();

	for (int i = 0; i < MeshTexture.size(); i++)
	{
		MeshTexture[i].Bind();
		//MeshTexture[i].TextureUnit(shader, "tex");
	}

	glDrawElements(GL_TRIANGLES, MeshIndices.size(), GL_UNSIGNED_INT, 0);
}

Mesh::~Mesh()
{
	MeshIndices = {};
	MeshTexture = {};
	MeshVertices = {};
	VAO.Delete();
}
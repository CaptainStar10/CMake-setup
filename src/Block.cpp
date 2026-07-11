#include "header/Block.hpp"

void Block::CreateNorthFace(std::vector<Vertex>& BlockVertices, std::vector<GLuint>& BlockIndices, unsigned int NumIndices)
{
	BlockVertices.push_back(Vertex{ glm::vec3(LocalBlockX + 0.5f,LocalBlockY + 0.5f,LocalBlockZ - 0.5f),glm::vec3(1.0f,0.0f,0.0f),glm::vec2(1.0f,1.0f) });
	BlockVertices.push_back(Vertex{ glm::vec3(LocalBlockX + 0.5f,LocalBlockY - 0.5f,LocalBlockZ - 0.5f),glm::vec3(0.0f,1.0f,0.0f),glm::vec2(1.0f,0.0f) });
	BlockVertices.push_back(Vertex{ glm::vec3(LocalBlockX - 0.5f,LocalBlockY - 0.5f,LocalBlockZ - 0.5f),glm::vec3(0.0f,0.0f,1.0f),glm::vec2(0.0f,0.0f) });
	BlockVertices.push_back(Vertex{ glm::vec3(LocalBlockX - 0.5f,LocalBlockY + 0.5f,LocalBlockZ - 0.5f),glm::vec3(1.0f,1.0f,1.0f),glm::vec2(0.0f,1.0f) });

	BlockIndices.push_back(NumIndices + 0);
	BlockIndices.push_back(NumIndices + 1);
	BlockIndices.push_back(NumIndices + 3);
	BlockIndices.push_back(NumIndices + 1);
	BlockIndices.push_back(NumIndices + 2);
	BlockIndices.push_back(NumIndices + 3);
}
void Block::CreateSouthFace(std::vector<Vertex>& BlockVertices, std::vector<GLuint>& BlockIndices, unsigned int NumIndices)
{
	BlockVertices.push_back(Vertex{ glm::vec3(LocalBlockX + 0.5f,LocalBlockY + 0.5f,LocalBlockZ + 0.5f),glm::vec3(1.0f,0.0f,0.0f),glm::vec2(1.0f,1.0f) });
	BlockVertices.push_back(Vertex{ glm::vec3(LocalBlockX - 0.5f,LocalBlockY + 0.5f,LocalBlockZ + 0.5f),glm::vec3(0.0f,1.0f,0.0f),glm::vec2(1.0f,0.0f) });
	BlockVertices.push_back(Vertex{ glm::vec3(LocalBlockX - 0.5f,LocalBlockY - 0.5f,LocalBlockZ + 0.5f),glm::vec3(0.0f,0.0f,1.0f),glm::vec2(0.0f,0.0f) });
	BlockVertices.push_back(Vertex{ glm::vec3(LocalBlockX + 0.5f,LocalBlockY - 0.5f,LocalBlockZ + 0.5f),glm::vec3(1.0f,1.0f,1.0f),glm::vec2(0.0f,1.0f) });

	BlockIndices.push_back(NumIndices + 0);
	BlockIndices.push_back(NumIndices + 1);
	BlockIndices.push_back(NumIndices + 3);
	BlockIndices.push_back(NumIndices + 1);
	BlockIndices.push_back(NumIndices + 2);
	BlockIndices.push_back(NumIndices + 3);
}
void Block::CreateEstFace(std::vector<Vertex>& BlockVertices, std::vector<GLuint>& BlockIndices, unsigned int NumIndices)
{
	BlockVertices.push_back(Vertex{ glm::vec3(LocalBlockX + 0.5f,LocalBlockY - 0.5f,LocalBlockZ + 0.5f),glm::vec3(1.0f,0.0f,0.0f),glm::vec2(1.0f,1.0f) });
	BlockVertices.push_back(Vertex{ glm::vec3(LocalBlockX + 0.5f,LocalBlockY - 0.5f,LocalBlockZ - 0.5f),glm::vec3(0.0f,1.0f,0.0f),glm::vec2(1.0f,0.0f) });
	BlockVertices.push_back(Vertex{ glm::vec3(LocalBlockX + 0.5f,LocalBlockY + 0.5f,LocalBlockZ - 0.5f),glm::vec3(0.0f,0.0f,1.0f),glm::vec2(0.0f,0.0f) });
	BlockVertices.push_back(Vertex{ glm::vec3(LocalBlockX + 0.5f,LocalBlockY + 0.5f,LocalBlockZ + 0.5f),glm::vec3(1.0f,1.0f,1.0f),glm::vec2(0.0f,1.0f) });

	BlockIndices.push_back(NumIndices + 0);
	BlockIndices.push_back(NumIndices + 1);
	BlockIndices.push_back(NumIndices + 3);
	BlockIndices.push_back(NumIndices + 1);
	BlockIndices.push_back(NumIndices + 2);
	BlockIndices.push_back(NumIndices + 3);
}
void Block::CreateWestFace(std::vector<Vertex>& BlockVertices, std::vector<GLuint>& BlockIndices, unsigned int NumIndices)
{
	BlockVertices.push_back(Vertex{ glm::vec3(LocalBlockX - 0.5f,LocalBlockY + 0.5f,LocalBlockZ - 0.5f),glm::vec3(1.0f,0.0f,0.0f),glm::vec2(1.0f,1.0f) });
	BlockVertices.push_back(Vertex{ glm::vec3(LocalBlockX - 0.5f,LocalBlockY - 0.5f,LocalBlockZ - 0.5f),glm::vec3(0.0f,1.0f,0.0f),glm::vec2(1.0f,0.0f) });
	BlockVertices.push_back(Vertex{ glm::vec3(LocalBlockX - 0.5f,LocalBlockY - 0.5f,LocalBlockZ + 0.5f),glm::vec3(0.0f,0.0f,1.0f),glm::vec2(0.0f,0.0f) });
	BlockVertices.push_back(Vertex{ glm::vec3(LocalBlockX - 0.5f,LocalBlockY + 0.5f,LocalBlockZ + 0.5f),glm::vec3(1.0f,1.0f,1.0f),glm::vec2(0.0f,1.0f) });

	BlockIndices.push_back(NumIndices + 0);
	BlockIndices.push_back(NumIndices + 1);
	BlockIndices.push_back(NumIndices + 3);
	BlockIndices.push_back(NumIndices + 1);
	BlockIndices.push_back(NumIndices + 2);
	BlockIndices.push_back(NumIndices + 3);
}
void Block::CreateUpFace(std::vector<Vertex>& BlockVertices, std::vector<GLuint>& BlockIndices, unsigned int NumIndices)
{
	BlockVertices.push_back(Vertex{ glm::vec3(LocalBlockX - 0.5f,LocalBlockY + 0.5f,LocalBlockZ + 0.5f),glm::vec3(1.0f,0.0f,0.0f),glm::vec2(1.0f,1.0f) });
	BlockVertices.push_back(Vertex{ glm::vec3(LocalBlockX + 0.5f,LocalBlockY + 0.5f,LocalBlockZ + 0.5f),glm::vec3(0.0f,1.0f,0.0f),glm::vec2(1.0f,0.0f) });
	BlockVertices.push_back(Vertex{ glm::vec3(LocalBlockX + 0.5f,LocalBlockY + 0.5f,LocalBlockZ - 0.5f),glm::vec3(0.0f,0.0f,1.0f),glm::vec2(0.0f,0.0f) });
	BlockVertices.push_back(Vertex{ glm::vec3(LocalBlockX - 0.5f,LocalBlockY + 0.5f,LocalBlockZ - 0.5f),glm::vec3(1.0f,1.0f,1.0f),glm::vec2(0.0f,1.0f) });

	BlockIndices.push_back(NumIndices + 0);
	BlockIndices.push_back(NumIndices + 1);
	BlockIndices.push_back(NumIndices + 3);
	BlockIndices.push_back(NumIndices + 1);
	BlockIndices.push_back(NumIndices + 2);
	BlockIndices.push_back(NumIndices + 3);
}
void Block::CreateDownFace(std::vector<Vertex>& BlockVertices, std::vector<GLuint>& BlockIndices, unsigned int NumIndices)
{
	BlockVertices.push_back(Vertex{ glm::vec3(LocalBlockX + 0.5f,LocalBlockY - 0.5f,LocalBlockZ - 0.5f),glm::vec3(1.0f,0.0f,0.0f),glm::vec2(1.0f,1.0f) });
	BlockVertices.push_back(Vertex{ glm::vec3(LocalBlockX + 0.5f,LocalBlockY - 0.5f,LocalBlockZ + 0.5f),glm::vec3(0.0f,1.0f,0.0f),glm::vec2(1.0f,0.0f) });
	BlockVertices.push_back(Vertex{ glm::vec3(LocalBlockX - 0.5f,LocalBlockY - 0.5f,LocalBlockZ + 0.5f),glm::vec3(0.0f,0.0f,1.0f),glm::vec2(0.0f,0.0f) });
	BlockVertices.push_back(Vertex{ glm::vec3(LocalBlockX - 0.5f,LocalBlockY - 0.5f,LocalBlockZ - 0.5f),glm::vec3(1.0f,1.0f,1.0f),glm::vec2(0.0f,1.0f) });

	BlockIndices.push_back(NumIndices + 0);
	BlockIndices.push_back(NumIndices + 1);
	BlockIndices.push_back(NumIndices + 3);
	BlockIndices.push_back(NumIndices + 1);
	BlockIndices.push_back(NumIndices + 2);
	BlockIndices.push_back(NumIndices + 3);
}
#pragma once
#include <Application/core/ShaderClass.h>
#include <Application/core/Texture.h>
#include <Application/core/VertexBufferObject.h>

enum BlockType
{
	Air = 0,
	Transparent = 1,
	Solid = 2,
	Translucent = 3,
};

class Block
{
	public:
		uint16_t LocalBlockX = 0, LocalBlockY = 0, LocalBlockZ = 0;
		uint16_t GlobalBlockX = 0, GlobalBlockY = 0, GlobalBlockZ = 0;
		uint8_t BlockID = 0;

		Texture BlockTexture;

		Shader BlockShader;

		BlockType Type = BlockType::Air;

		void CreateNorthFace(std::vector<Vertex>& BlockVertices, std::vector<GLuint>& BlockIndices, unsigned int NumIndices);
		void CreateSouthFace(std::vector<Vertex>& BlockVertices, std::vector<GLuint>& BlockIndices, unsigned int NumIndices);
		void CreateEstFace(std::vector<Vertex>& BlockVertices, std::vector<GLuint>& BlockIndices, unsigned int NumIndices);
		void CreateWestFace(std::vector<Vertex>& BlockVertices, std::vector<GLuint>& BlockIndices, unsigned int NumIndices);
		void CreateUpFace(std::vector<Vertex>& BlockVertices, std::vector<GLuint>& BlockIndices, unsigned int NumIndices);
		void CreateDownFace(std::vector<Vertex>& BlockVertices, std::vector<GLuint>& BlockIndices, unsigned int NumIndices);
};
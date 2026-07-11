#pragma once
#include <Application/core/Mesh.h>
#include <noise/FastNoise.h>
#include <cmath>
#include <thread>

#include "Block.hpp"

#define ChunckSize 16
#define ChunckHeight 16

class Chunck
{
	public:
		Chunck(int xPosition, int zPosition);
		~Chunck();

		void GenerateData();
		void GenerateChunck(Shader& shader);
		void RenderChunck(Shader& shader);

		int GlobalChunckPositionX = 0, GlobalChunckPositionZ = 0;
		int LocalBlockPositionX = 0, LocalBlockPositionY = 0, LocalBlockPositionZ = 0;

		std::vector<Vertex> ChunckVertices;
		std::vector<GLuint> ChunckIndices;
		std::vector<Texture> ChunckTextures;

	private:
		int GetEquationForPositionX(int x, int y, int z);
		int GetEquationForPositionY(int x, int y, int z);
		int GetEquationForPositionZ(int x, int y, int z);

		void CreateChunckThreadGeneration();

		VertexArrayObject VAO;
		Texture ChunckTexture;

		//-----------------		 Y		--		 X      --		 Z     --
		Block BlockList[ChunckHeight + 2][ChunckSize + 2][ChunckSize + 2];
		int BlockIdList[ChunckHeight + 2][ChunckSize + 2][ChunckSize + 2];
};
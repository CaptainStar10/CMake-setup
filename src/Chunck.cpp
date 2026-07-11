#include "header/Chunck.hpp"

Chunck::Chunck(int xPosition, int zPosition)
{
	GlobalChunckPositionX = xPosition;
	GlobalChunckPositionZ = zPosition;

	LocalBlockPositionX = static_cast<int>(GlobalChunckPositionX / ChunckSize);
	LocalBlockPositionY = 0;
	LocalBlockPositionZ = static_cast<int>(GlobalChunckPositionZ / ChunckSize);
}
void Chunck::CreateChunckThreadGeneration()
{

}

int Chunck::GetEquationForPositionX(int x, int y, int z)
{
	return x;
}
int Chunck::GetEquationForPositionY(int x, int y, int z)
{ 
	return y;
}
int Chunck::GetEquationForPositionZ(int x, int y, int z)
{
	return z;
}

void Chunck::GenerateData()
{
	for (int y = 0; y < ChunckHeight; y++)
	{
		for (int x = 0, LocalX = LocalBlockPositionX; x < ChunckSize; x++, LocalX++)
		{
			for (int z = 0, LocalZ = LocalBlockPositionZ; z < ChunckSize; z++, LocalZ++)
			{
				Block* pBlock1 = new Block;
				pBlock1->LocalBlockX = GetEquationForPositionX(LocalX, y, LocalZ);
				pBlock1->LocalBlockY = GetEquationForPositionY(LocalX, y, LocalZ);
				pBlock1->LocalBlockZ = GetEquationForPositionZ(LocalX, y, LocalZ);
				pBlock1->Type = (y <= ChunckHeight / 2) ? BlockType::Solid : BlockType::Air;
				BlockList[y][x][z] = *pBlock1;
				BlockIdList[y][x][z] = 1;
				delete pBlock1;
			}
		}
	}
}
void Chunck::GenerateChunck(Shader& shader)
{
	bool GenerateLeft = true, GenerateRight = true, GenerateUp = true, GenerateDown = true, GenerateFront = true, GenerateBack = true;
	bool CalculateForHigherBlocks = false;

	unsigned int NumIndices = 0;
	for (int y = 0; y < ChunckHeight; y++)
	{
		for (int x = 0; x < ChunckSize; x++)
		{
			for (int z = 0; z < ChunckSize; z++)
			{
				if ((x > 0 && x < ChunckSize - 1) && (y > 0 && y < ChunckHeight - 1) && (z > 0 && z < ChunckSize - 1))
				{
					if (BlockIdList[y + 1][x][z] == 0)
					{
						BlockList[y][x][z].CreateUpFace(ChunckVertices, ChunckIndices, NumIndices);
						NumIndices += 4;
					}
					if (BlockIdList[y - 1][x][z] == 0)
					{
						BlockList[y][x][z].CreateDownFace(ChunckVertices, ChunckIndices, NumIndices);
						NumIndices += 4;
					}
					if (BlockIdList[y][x + 1][z] == 0)
					{
						BlockList[y][x][z].CreateEstFace(ChunckVertices, ChunckIndices, NumIndices);
						NumIndices += 4;
					}
					if (BlockIdList[y][x - 1][z] == 0)
					{
						BlockList[y][x][z].CreateWestFace(ChunckVertices, ChunckIndices, NumIndices);
						NumIndices += 4;
					}
					if (BlockIdList[y][x][z - 1] == 0)
					{
						BlockList[y][x][z].CreateNorthFace(ChunckVertices, ChunckIndices, NumIndices);
						NumIndices += 4;
					}
					if (BlockIdList[y][x][z + 1] == 0)
					{
						BlockList[y][x][z].CreateSouthFace(ChunckVertices, ChunckIndices, NumIndices);
						NumIndices += 4;
					}
				}
				else
				{
					if (x == 0)
					{
						BlockList[y][x][z].CreateWestFace(ChunckVertices, ChunckIndices, NumIndices);
						NumIndices += 4;
					}
					if (y == 0)
					{
						BlockList[y][x][z].CreateDownFace(ChunckVertices, ChunckIndices, NumIndices);
						NumIndices += 4;
					}
					if (z == 0)
					{
						BlockList[y][x][z].CreateNorthFace(ChunckVertices, ChunckIndices, NumIndices);
						NumIndices += 4;
					}
					if (x == ChunckSize - 1)
					{
						BlockList[y][x][z].CreateEstFace(ChunckVertices, ChunckIndices, NumIndices);
						NumIndices += 4;
					}
					if (y == ChunckHeight - 1)
					{
						BlockList[y][x][z].CreateUpFace(ChunckVertices, ChunckIndices, NumIndices);
						NumIndices += 4;
					}
					if (z == ChunckSize - 1)
					{
						BlockList[y][x][z].CreateSouthFace(ChunckVertices, ChunckIndices, NumIndices);
						NumIndices += 4;
					}
				}
			}
		}  
	}

	VAO.Bind();
	VertexBufferObject VBO(ChunckVertices);
	VBO.Bind();
	ElementBufferObject EBO(ChunckIndices);
	EBO.Bind();

	VAO.Link(VBO, 0, 3, GL_FLOAT, sizeof(Vertex), (void*)(0 * sizeof(float)));
	VAO.Link(VBO, 1, 3, GL_FLOAT, sizeof(Vertex), (void*)(3 * sizeof(float)));
	VAO.Link(VBO, 2, 2, GL_FLOAT, sizeof(Vertex), (void*)(6 * sizeof(float)));

	VBO.Unbind();
	VAO.Unbind();

	ChunckTexture.CreateTexture("./resources/grass_tile.png");
	ChunckTexture.Bind();
	ChunckTexture.TextureUnit(shader, "tex");
	ChunckTexture.Unbind();
}
void Chunck::RenderChunck(Shader& shader)
{
	shader.Activate();
	ChunckTexture.Bind();
	VAO.Bind();
	glDrawElements(GL_TRIANGLES, ChunckIndices.size(), GL_UNSIGNED_INT, 0);
}
Chunck::~Chunck()
{
	VAO.Delete();
}
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <array>


#include<game/game.h>
#include "block.h"

class Chunk
{
private:
	std::vector<float> noiseOutput;
	glm::ivec3 pos;
	glm::ivec3 dimensions = glm::ivec3(16, 16, 16);
	Renderdata rd;
	Renderdata transparent_rd;
	std::vector<Vertex> verticies;
	std::vector<Vertex> transparent_verticies;
	std::vector<unsigned int> tris;
	std::vector<unsigned int> transparent_tris;
	Crazycraft::BlockDefs bd;
public:
	unsigned char getBlock(int x, int y, int z);

	bool isBlockTransparent(int x, int y, int z);

	Chunk(glm::ivec3 _pos);

	void generate();

	void UpdateRenderData();

	void render();

};
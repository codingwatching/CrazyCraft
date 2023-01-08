#ifndef __CHUNK_H__
#define __CHUNK_H__

#include <iostream>
#include <vector>


#include<game/game.h>
#include "block.h"

class Chunk
{
private:
	glm::ivec3 pos;
	glm::ivec3 dimensions = glm::ivec3(16, 16, 16);
	Renderdata rd;
	Renderdata transparent_rd;
	std::vector<Vertex> verticies;
	std::vector<Vertex> transparent_verticies;
	std::vector<unsigned int> tris;
	std::vector<unsigned int> transparent_tris;
public:
	unsigned char getBlock(int x, int y, int z);

	bool isBlockTransparent(int x, int y, int z);

	Chunk(glm::ivec3 _pos);

	void generate();

	void UpdateRenderData();

	void render();

};
#endif // __CHUNK_H__
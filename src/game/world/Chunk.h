#ifndef __CHUNK_H__
#define __CHUNK_H__

#include <iostream>
#include <vector>


#include<game/game.h>
#include "block.h"
class Chunk;// frick this complex clusterf***

#include <game/world/World.h>

class Chunk
{
private:
	World parent;
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

	Chunk(glm::ivec3 _pos,World parent);

	void generate();

	void UpdateRenderData();

	void render();

};
#endif // __CHUNK_H__
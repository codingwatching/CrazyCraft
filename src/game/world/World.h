#ifndef __WORLD_H__
#define __WORLD_H__

#include <Chunk.h>

class World{
private:
World();
int render_distance = 2;
std::vector<Chunk> chunks;
std::vector<float> noiseOutput;
public:
Crazycraft::BlockDefs bd;
void update_chunks();
void set_render_distance(int new_dist);
void render();
int GetBlock(int x,int y,int z);
static World& getInstance();
};

#endif // __WORLD_H__
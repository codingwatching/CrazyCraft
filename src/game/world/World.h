#ifndef __WORLD_H__
#define __WORLD_H__

class World;// frick this complex clusterf***

#include <Chunk.h>

class World{
private:
int render_distance = 2;
std::vector<Chunk> chunks;
std::vector<float> noiseOutput;
public:
Crazycraft::BlockDefs bd;
void update_chunks();
void set_render_distance(int new_dist);
void render();
int GetBlock(int x,int y,int z);
World();

};

#endif // __WORLD_H__
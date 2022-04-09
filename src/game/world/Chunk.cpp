#include "Chunk.h"
#include "game/world/Voxeldata.h"
Chunk::Chunk(){

for(int i = 0;i <= 24;i++)
    verticies.push_back(Vertex(voxpos[i],grassuv[i]));

for(int i = 0;i <= 36;i++)
    tris.push_back(voxtris[i]);
    
}
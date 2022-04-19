#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <array>


#include<game/game.h>
#include <opengl/debug.h>
#include "block.h"
class Chunk{
    private:
    Renderdata rd;
    std::vector<Vertex> verticies;
    std::vector<unsigned int> tris;
    Crazycraft::BlockDefs bd;
    public:
    Chunk();
    void generate();
    void UpdateRenderData();
    void render();

};
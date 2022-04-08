#include<game/game.h>
class Chunk{
    public:
    std::array<Vertex,24> verticies;
    std::array<unsigned int,36> tris;
    Chunk();
};
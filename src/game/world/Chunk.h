#include<game/game.h>
class Chunk{
    private:
    Renderdata rd;
    std::vector<Vertex> verticies;
    std::vector<unsigned int> tris;
    public:
    Chunk();
    void generate();
    void UpdateRenderData();
    void render();

};
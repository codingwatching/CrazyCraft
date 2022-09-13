#include "World.h"


#include <FastNoise/FastNoise.h>

World::World(){
//varibles
render_distance = 2;
//initializing the chunks
for (int x =(render_distance)*-1;x < render_distance; x++)// diffrent cuz the posoition needs to bee good
{
    for (int y = (render_distance)*-1;y < render_distance; y++)
    {
        for (int z = (render_distance)*-1;z < render_distance; z++)
        {
            chunks.push_back(Chunk(glm::vec3(x,y,z),this));

        }
    }
}
//noise stuff
noiseOutput = std::vector<float>(16*16);
auto fnGenerator = FastNoise::New<FastNoise::Simplex>();
fnGenerator->GenUniformGrid2D(noiseOutput.data(), 0, 0, (render_distance*2) * 16,(render_distance*2) * 16, 0.2f,122);
// defining the blocks
bd.addBlock(Crazycraft::Block("E",1,Crazycraft::Texture(0,0,0,0,0,0),true));
bd.addBlock(Crazycraft::Block("E",1,Crazycraft::Texture(1,1,1,1,3,2)));
bd.addBlock(Crazycraft::Block("E",1,Crazycraft::Texture(2,2,2,2,2,2)));
bd.addBlock(Crazycraft::Block("E",1,Crazycraft::Texture(5,5,5,5,5,5)));
bd.addBlock(Crazycraft::Block("E",1,Crazycraft::Texture(33,33,33,33,33,33),true));
}

void World::update_chunks()
{
for (int x =0;x < render_distance*2; x++)
{
    for (int y = 0;y < render_distance*2; y++)
    {
        for (int z = 0;z < render_distance*2; z++)
        {
            chunks[(x * render_distance*2) + (y * render_distance*2) + z].generate();
            chunks[(x * render_distance*2) + (y * render_distance*2) + z].UpdateRenderData();

        }
    }
}

}

void World::set_render_distance(int new_dist)
{
    render_distance = new_dist;
    update_chunks();
}

void World::render()
{
for (int x =0;x < render_distance*2; x++)
{
    for (int y = 0;y < render_distance*2; y++)
    {
        for (int z = 0;z < render_distance*2; z++)
        {
            chunks[(x * render_distance*2) + (y * render_distance*2) + z].render();
            
        }
    }
}
}

int World::GetBlock(int x,int y,int z)
{
    int l = 4 + (noiseOutput[((x * 16) + z)]) * 2;
	if (y <= l - 5)
		return 3;
	if (y <= l - 1)
		return 2;
	if (y == l)
		return 1;
	return 0;
}

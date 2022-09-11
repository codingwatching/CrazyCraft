#include "World.h"
World::World(){
render_distance = 2;
for (int x =(render_distance)*-1;x < render_distance; x++)// diffrent cuz the posoition needs to bee good
{
    for (int y = (render_distance)*-1;y < render_distance; y++)
    {
        for (int z = (render_distance)*-1;z < render_distance; z++)
        {
            chunks.push_back(Chunk(glm::vec3(x,y,z)));

        }
    }
}
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

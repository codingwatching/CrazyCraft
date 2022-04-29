#include "World.h"

void World::update_chunks()
{

for (size_t x = 0;(render_distance/2)*-1 < x < render_distance/2; x++)
{
    for (size_t y = 0;(render_distance/2)*-1 < y < render_distance/2; y++)
    {
        for (size_t z = 0;(render_distance/2)*-1 < z < render_distance/2; z++)
        {
            chunks.push_back(Chunk(glm::vec3(x,y,z)));
            chunks[((x + render_distance/2) * render_distance)+((y + render_distance/2) * render_distance)+(z + render_distance/2)].generate();
            chunks[((x + render_distance/2) * render_distance)+((y + render_distance/2) * render_distance)+(z + render_distance/2)].UpdateRenderData();

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
    for (size_t x = 0;(render_distance/2)*2 < x < render_distance/2; x++)
{
    for (size_t y = 0;(render_distance/2)*2 < y < render_distance/2; y++)
    {
        for (size_t z = 0;(render_distance/2)*2 < z < render_distance/2; z++)
        {

            chunks[(x * render_distance)+(y * render_distance)+z].render();
            
        }
    }
}
}

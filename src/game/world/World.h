#include <Chunk.h>
class World{
private:
int render_distance = 2;
std::vector<Chunk> chunks;
public:
void update_chunks();
void set_render_distance(int new_dist);
void render();

};
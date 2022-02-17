#define POS_COUNT 4
#define UV_COUNT 4
#define TRIANGLE_COUNT 6

namespace CrazyCraft{

namespace Sounds{
    
}
namespace Blocks{
    
  
}
namespace TexturePacker{
    
}
namespace Sounds{
    
}
namespace Mesh{
void build(glm::vec3 positions[],glm::vec2 uvs[],unsigned int triangles[],unsigned int& vb,unsigned int& ib){
    float vbd[POS_COUNT * 3 + UV_COUNT *2];
    for (int i; i <= (POS_COUNT + UV_COUNT);i++){
        if(i % 5 == 1){
            vbd[i] = positions[i / 5].x;
        }
        if(i % 5 == 2){
            vbd[i] = positions[i / 5].y;
        }
        if(i % 5 == 3){
            vbd[i] = positions[i / 5].z;
        }
        if(i % 5 == 4){
            vbd[i] = uvs[i / 5].x;
        }
        if(i % 5 == 5){
            vbd[i] = uvs[i / 5].y;
        }
    }
    vb = VertexBuffer(vbd, sizeof(vbd)).Getrendererid();
    ib = IndexBuffer(triangles, TRIANGLE_COUNT).Getrendererid();
}
}
}
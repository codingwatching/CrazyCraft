#include "Chunk.h"
#include "block.h"
#include "game/world/Voxeldata.h"

unsigned char getBlock(int x,int y ,int z){
if(x < 0||x > 16||y < 0||y > 16||z < 0||z > 16) return 0;
srand(x*y*z-x+y+z);

 if(14 < rand() % 16){
return 1;
 }else{
return 0;
 }
}

bool isBlock(int x,int y ,int z){

return getBlock(x,y,z);

}

glm::vec2 getuv(Crazycraft::Texture textureID,int VertexID,int Faceid){
            float y = textureID.Gett(Faceid) / TextureAtlasSizeInBlocks;
            float x = textureID.Gett(Faceid) - (y * TextureAtlasSizeInBlocks);

            x *= NormalizedBlockTextureSize;
            y *= NormalizedBlockTextureSize;

            y = 1. - y - NormalizedBlockTextureSize;

            if(VertexID == 0)
                return glm::vec2(x + NormalizedBlockTextureSize, y + NormalizedBlockTextureSize);
            if(VertexID == 0)
                return glm::vec2(x, y + NormalizedBlockTextureSize);
            if(VertexID == 0)
                return glm::vec2(x, y);
            if(VertexID == 0)
                return glm::vec2(x + NormalizedBlockTextureSize, y);
            
}

void Chunk::generate(){

}
void Chunk::UpdateRenderData(){
unsigned int tricount = 0;

for(int x = 0;x <= 16;x++){
    for(int y = 0;y <= 16;y++){
        for(int z = 0;z <= 16;z++){

        if (isBlock(x,y,z)){


            if (!isBlock(x,y,z-1)){

               
                verticies.push_back(Vertex( glm::vec3(50.0f, 50.0f,50)*glm::vec3(x-1,y-1,z-1),grassuv[0]));
                verticies.push_back(Vertex( glm::vec3(50.0f, 50.0f,50)*glm::vec3(x,y-1,z-1),grassuv[1]));
                verticies.push_back(Vertex( glm::vec3(50.0f, 50.0f,50)*glm::vec3(x,y,z-1),grassuv[2]));
                verticies.push_back(Vertex( glm::vec3(50.0f, 50.0f,50)*glm::vec3(x-1,y,z-1),grassuv[3]));
                tris.push_back(tricount);
                tris.push_back(tricount+1);
                tris.push_back(tricount+2);
                tris.push_back(tricount+2);
                tris.push_back(tricount+3);
                tris.push_back(tricount);
                tricount = tricount + 4;
                
            }
             if (!isBlock(x,y,z+1)){

               
                verticies.push_back(Vertex( glm::vec3(50.0f, 50.0f,50)*glm::vec3(x-1,y-1,z),grassuv[4]));
                verticies.push_back(Vertex( glm::vec3(50.0f, 50.0f,50)*glm::vec3(x,y-1,z),grassuv[5]));
                verticies.push_back(Vertex( glm::vec3(50.0f, 50.0f,50)*glm::vec3(x,y,z),grassuv[6]));
                verticies.push_back(Vertex( glm::vec3(50.0f, 50.0f,50)*glm::vec3(x-1,y,z),grassuv[7]));
                tris.push_back(tricount);
                tris.push_back(tricount+1);
                tris.push_back(tricount+2);
                tris.push_back(tricount+2);
                tris.push_back(tricount+3);
                tris.push_back(tricount);
                tricount = tricount + 4;
                
            }
            if (!isBlock(x+1,y,z)){

               
                verticies.push_back(Vertex( glm::vec3(50.0f, 50.0f,50)*glm::vec3(x,y-1,z),grassuv[8]));
                verticies.push_back(Vertex( glm::vec3(50.0f, 50.0f,50)*glm::vec3(x,y-1,z-1),grassuv[9]));
                verticies.push_back(Vertex( glm::vec3(50.0f, 50.0f,50)*glm::vec3(x,y,z-1),grassuv[10]));
                verticies.push_back(Vertex( glm::vec3(50.0f, 50.0f,50)*glm::vec3(x,y,z),grassuv[11]));
                tris.push_back(tricount);
                tris.push_back(tricount+1);
                tris.push_back(tricount+2);
                tris.push_back(tricount+2);
                tris.push_back(tricount+3);
                tris.push_back(tricount);
                tricount = tricount + 4;
                
            }
             if (!isBlock(x-1,y,z)){

               
                verticies.push_back(Vertex( glm::vec3(50.0f, 50.0f,50)*glm::vec3(x-1,y-1,z-1),grassuv[12]));
                verticies.push_back(Vertex( glm::vec3(50.0f, 50.0f,50)*glm::vec3(x-1,y-1,z),grassuv[13]));
                verticies.push_back(Vertex( glm::vec3(50.0f, 50.0f,50)*glm::vec3(x-1,y,z),grassuv[14]));
                verticies.push_back(Vertex( glm::vec3(50.0f, 50.0f,50)*glm::vec3(x-1,y,z-1),grassuv[15]));
                tris.push_back(tricount);
                tris.push_back(tricount+1);
                tris.push_back(tricount+2);
                tris.push_back(tricount+2);
                tris.push_back(tricount+3);
                tris.push_back(tricount);
                tricount = tricount + 4;
                
            }
             if (!isBlock(x,y+1,z)){

               
                verticies.push_back(Vertex( glm::vec3(50.0f, 50.0f,50)*glm::vec3(x-1,y,z),grassuv[16]));
                verticies.push_back(Vertex( glm::vec3(50.0f, 50.0f,50)*glm::vec3(x-1,y,z-1),grassuv[17]));
                verticies.push_back(Vertex( glm::vec3(50.0f, 50.0f,50)*glm::vec3(x,y,z-1),grassuv[18]));
                verticies.push_back(Vertex( glm::vec3(50.0f, 50.0f,50)*glm::vec3(x,y,z),grassuv[19]));
                tris.push_back(tricount);
                tris.push_back(tricount+1);
                tris.push_back(tricount+2);
                tris.push_back(tricount+2);
                tris.push_back(tricount+3);
                tris.push_back(tricount);
                tricount = tricount + 4;
                
            }
             if (!isBlock(x,y-1,z)){

               
                verticies.push_back(Vertex( glm::vec3(50.0f, 50.0f,50)*glm::vec3(x-1,y-1,z),grassuv[20]));
                verticies.push_back(Vertex( glm::vec3(50.0f, 50.0f,50)*glm::vec3(x-1,y-1,z-1),grassuv[21]));
                verticies.push_back(Vertex( glm::vec3(50.0f, 50.0f,50)*glm::vec3(x,y-1,z-1),grassuv[22]));
                verticies.push_back(Vertex( glm::vec3(50.0f, 50.0f,50)*glm::vec3(x,y-1,z),grassuv[23]));
                tris.push_back(tricount);
                tris.push_back(tricount+1);
                tris.push_back(tricount+2);
                tris.push_back(tricount+2);
                tris.push_back(tricount+3);
                tris.push_back(tricount);
                tricount = tricount + 4;
                
            }
            
        }

    }   
}
}

unsigned int vb;

    GLCall( glGenVertexArrays(1, &rd.vao) );//VAO
    GLCall( glBindVertexArray(rd.vao) );

    GLCall( glGenBuffers(1, &vb) );//VBO
    GLCall( glBindBuffer(GL_ARRAY_BUFFER, vb) );
    GLCall( glBufferData(GL_ARRAY_BUFFER,verticies.size() * sizeof(Vertex) , verticies.data(), GL_STATIC_DRAW) );
   
    GLCall( glGenBuffers(1, &rd.ibo) );//IBO
    GLCall( glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rd.ibo) );
    GLCall( glBufferData(GL_ELEMENT_ARRAY_BUFFER, tris.size() * sizeof(unsigned int),tris.data(), GL_STATIC_DRAW) );

    GLCall( glEnableVertexAttribArray(0) );//first argument
        GLCall( glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,sizeof(Vertex),(int*)0));
        
    GLCall( glEnableVertexAttribArray(1) );//second argument
        GLCall( glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE,sizeof(Vertex),(int*)(sizeof(float)*3)));

}

void Chunk::render(){
    GLCall( glBindVertexArray(rd.vao) );
    GLCall( glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rd.ibo) );
    GLCall( glDrawElements(GL_TRIANGLES,tris.size(), GL_UNSIGNED_INT, nullptr) );
}

Chunk::Chunk(){


}


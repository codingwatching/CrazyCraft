#include "Chunk.h"
#include "block.h"
#include "game/world/Voxeldata.h"

unsigned char getBlock(int x,int y ,int z){
if(x < 0||x > 16||y < 0||y > 16||z < 0||z > 16) return 0;
srand(x*z-x+z);

 if(y <= rand() % 16){
return 1;
 }else{
return 0;
 }

}

bool isBlock(int x,int y ,int z){

return getBlock(x,y,z);

}

Chunk::Chunk(){
   unsigned int tricount = 0;

for(int x = 0;x <= 16;x++){
    for(int y = 0;y <= 16;y++){
        for(int z = 0;z <= 16;z++){

        if (isBlock(x,y,z)){
             std::cout << "Block at :"<< x << " "  << y << " " << z << " " << std::endl;
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
}


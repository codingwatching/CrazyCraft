
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <array>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
struct Vertex{
    glm::vec3 pos;
    glm::vec2 uv;
    Vertex( glm::vec3 _pos,glm::vec2 _uv){
        pos = _pos;
        uv = _uv; 
    }
};


glm::vec3 voxpos[24]{
    //front
    glm::vec3(-50.0f, -50.0f,-50),
    glm::vec3(50.0f, -50.0f,-50),
    glm::vec3(50.0f, 50.0f,-50),
    glm::vec3(-50.0f, 50.0f,-50),
    //back
    glm::vec3(-50.0f, -50.0f,50),
    glm::vec3(50.0f, -50.0f,50),
    glm::vec3(50.0f, 50.0f,50),
    glm::vec3(-50.0f, 50.0f,50),
    //side
    glm::vec3(50.0f, -50.0f,50),
    glm::vec3(50.0f, -50.0f,-50),
    glm::vec3(50.0f, 50.0f,-50),
    glm::vec3(50.0f, 50.0f,50),
    //another side
    glm::vec3(-50.0f, -50.0f,-50),
    glm::vec3(-50.0f, -50.0f,50),
    glm::vec3(-50.0f, 50.0f,50),
    glm::vec3(-50.0f, 50.0f,-50),
    //top
    glm::vec3(-50.0f, 50.0f,50),
    glm::vec3(-50.0f, 50.0f,-50),
    glm::vec3(50.0f, 50.0f,-50),
    glm::vec3(50.0f, 50.0f,50),
    //bottom
    glm::vec3(-50.0f, -50.0f,50),
    glm::vec3(-50.0f, -50.0f,-50),
    glm::vec3(50.0f, -50.0f,-50),
    glm::vec3(50.0f, -50.0f,50)
};

glm::vec2 grassuv[24]{
    //front
    glm::vec2(0.0f, 0.9375f),
    glm::vec2(0.0625f, 0.9375),
    glm::vec2(0.0625f, 1.),
    glm::vec2(0.0f, 1.),
    //back
    glm::vec2(0.0f, 0.9375f),
    glm::vec2(0.0625f, 0.9375),
    glm::vec2(0.0625f, 1.),
    glm::vec2(0.0f, 1.),
    //side
    glm::vec2(0.0f, 0.9375f),
    glm::vec2(0.0625f, 0.9375),
    glm::vec2(0.0625f, 1.),
    glm::vec2(0.0f, 1.),
    //another side
    glm::vec2(0.0f, 0.9375f),
    glm::vec2(0.0625f, 0.9375),
    glm::vec2(0.0625f, 1.),
    glm::vec2(0.0f, 1.),
    //top
    glm::vec2(0.125,0.9375),
    glm::vec2(0.1875,0.9375),
    glm::vec2(0.1875,1.),
    glm::vec2(0.125,1.),
    //bottom
    glm::vec2(0.0625, 0.9375),
    glm::vec2(0.125, 0.9375),
    glm::vec2(0.125, 1.),
    glm::vec2(0.0625, 1.)
};
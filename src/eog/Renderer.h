#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <eog/Debug.h>
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

class Renderer
{
    public:
        void Clear() const;
        void Draw(const VertexArray& va, const IndexBuffer ib, const Shader& shader) const;
};

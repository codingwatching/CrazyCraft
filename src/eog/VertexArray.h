#pragma once
#include "VertexBuffer.h"
class VertexArray
{
    private:
        unsigned int m_RendererID;
        unsigned int m_SavedIndex;
        unsigned int m_SavedOffset;
        unsigned int m_Stride;

    public:
        VertexArray();
        ~VertexArray();

        void AddBuffer(const VertexBuffer& vb,Element elements...);
        void Bind() const;
        void Unbind() const;
};
#include "Renderer.h"



struct Element
{
    unsigned int type;
    unsigned int count;
    unsigned char normalized;

    static unsigned int GetSizeOfType(unsigned int type)
    {
        switch (type)
        {
            case GL_FLOAT         : return sizeof(GLfloat);
            case GL_UNSIGNED_INT  : return sizeof(GLuint);
            case GL_UNSIGNED_BYTE : return sizeof(GLbyte);
        }
        ASSERT(false);
        return 0;
    }
};



#pragma once

class VertexBuffer
{
    private:
        unsigned int m_RendererID;

    public:
        VertexBuffer(const void* data, unsigned int size);
        VertexBuffer(unsigned int idtocopy);
        ~VertexBuffer();
        unsigned int Getrendererid(); 
        void Bind() const;
        void Unbind() const;
};

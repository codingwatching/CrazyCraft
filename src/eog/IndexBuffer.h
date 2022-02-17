#pragma once

class IndexBuffer
{
    private:
        unsigned int m_RendererID;
        unsigned int m_Count;

    public:
        IndexBuffer(const unsigned int* indices, unsigned int count);
        IndexBuffer(unsigned int idtocopy);
        ~IndexBuffer();
        unsigned int Getrendererid(); 
        void Bind() const;
        void Unbind() const;

        inline unsigned int GetCount() const { return m_Count; }
};

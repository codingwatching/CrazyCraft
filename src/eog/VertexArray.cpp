
#include "Debug.h"
#include "VertexArray.h"


VertexArray::VertexArray() : m_SavedIndex(0),m_SavedOffset(0),m_Stride(0)
{
    GLCall( glGenVertexArrays(1, &m_RendererID) );
}

VertexArray::~VertexArray()
{
    GLCall( glDeleteVertexArrays(1, &m_RendererID) );
}

void VertexArray::AddBuffer(const VertexBuffer& vb,...)
{
    Bind();
    vb.Bind();
    
    
    for (int i = 0 ;i < elements.size();i++){
        const Element element = elements[i];
        m_Stride += element.count * Element::GetSizeOfType(type);
    }
    for (unsigned int i = m_SavedIndex; i < elements.size() ; i++)
    {

        const Element element = elements[i];
        GLCall( glEnableVertexAttribArray(i) );
        GLCall( glVertexAttribPointer(i, element.count, element.type, element.normalized,
                                      m_Stride,(int*)m_SavedOffset));
        m_SavedOffset += element.count * Element::GetSizeOfType(element.type);
        m_SavedIndex = i;

    }
}

void VertexArray::Bind() const
{
    GLCall( glBindVertexArray(m_RendererID) );
}

void VertexArray::Unbind() const
{
    GLCall( glBindVertexArray(0) );
};

#include "VAO.hpp"

namespace ft {

    VAO::VAO()
    {
        glCreateVertexArrays(1, &_id);
    }

    VAO::~VAO()
    {
        glDeleteVertexArrays(1, &_id);
    }

    void VAO::Bind()
    {
        glBindVertexArray(_id);
    }

    void VAO::Unbind()
    {
        glBindVertexArray(0);
    }

    void VAO::AddVBO(VBO& vbo)
    {
        unsigned int binding_index = 0; /* TODO: handle binding index differently */
        vbo.Bind(_id, binding_index);
        _vbos.push_back(&vbo);
        /* TODO: create VBO format struct */
        /* POS */
        glEnableVertexArrayAttrib(_id, 0);
        glVertexArrayAttribFormat(_id, 0, 3, GL_FLOAT, GL_FALSE, offsetof(Vertex, position));
        glVertexArrayAttribBinding(_id, 0, binding_index);
        /* TEX_COORD */
        glEnableVertexArrayAttrib(_id, 1);
        glVertexArrayAttribFormat(_id, 1, 2, GL_FLOAT, GL_FALSE, offsetof(Vertex, tex_coord));
        glVertexArrayAttribBinding(_id, 1, binding_index);
        /* COLOR */
        glEnableVertexArrayAttrib(_id, 2);
        glVertexArrayAttribFormat(_id, 2, 4, GL_FLOAT, GL_FALSE, offsetof(Vertex, color));
        glVertexArrayAttribBinding(_id, 2, binding_index);
        /* NORMAL */
        glEnableVertexArrayAttrib(_id, 3);
        glVertexArrayAttribFormat(_id, 3, 3, GL_FLOAT, GL_FALSE, offsetof(Vertex, normal));
        glVertexArrayAttribBinding(_id, 4, binding_index);
        /* MATERIAL ID */
        glEnableVertexArrayAttrib(_id, 4);
        glVertexArrayAttribFormat(_id, 4, 1, GL_FLOAT, GL_FALSE, offsetof(Vertex, material_id));
        glVertexArrayAttribBinding(_id, 4, binding_index);
    }
}
#include "VBO.hpp"

namespace ft {

    VBO::VBO(unsigned int batch_size)
        : _data_offset(0), _batch_size(batch_size)
    {
        glCreateBuffers(1, &_id);
        glNamedBufferData(_id, _batch_size, nullptr, GL_STATIC_DRAW);
    }

    VBO::VBO(const std::vector<Vertex>& vertices, unsigned int cnt)
        : VBO()
    {
        AddData(vertices, cnt);
    }

    VBO::~VBO()
    {
        glDeleteBuffers(1, &_id);
    }

    void VBO::AddData(const std::vector<Vertex>& vertices, unsigned int cnt)
    {
        if (cnt == 0)
            cnt = vertices.size();
        unsigned int new_data_size = cnt * sizeof(Vertex);
        if (_data_offset + new_data_size >= _batch_size)
            return; /* NOT ENOUGH SPACE */
        glNamedBufferSubData(_id, _data_offset, new_data_size, &vertices[0]);
        _data_offset += new_data_size;
    }

    void VBO::Bind(unsigned int vao_id, unsigned int binding_index)
    {
        glVertexArrayVertexBuffer(vao_id, binding_index, _id, 0, sizeof(Vertex));
    }

    void VBO::Clear()
    {
        _data_offset = 0;
    }

}
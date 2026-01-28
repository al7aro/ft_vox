#pragma once

#include <vector>

#include <glad/glad.h>

#include "Vertex.hpp"

namespace ft {

    class VBO
    {
    private:
        unsigned int _id;
        unsigned int _data_offset;
        unsigned int _batch_size;
    public:
        VBO(unsigned int batch_size = sizeof(Vertex) * 6 * 6 * 1); /* default size of 1 CUBE */
        VBO(const std::vector<Vertex>& vertices, unsigned int cnt = 0);
        ~VBO();

        void AddData(const std::vector<Vertex>& vertices, unsigned int cnt = 0);
        void Bind(unsigned int vao_id, unsigned int binding_index);

        void Clear();
    };

}
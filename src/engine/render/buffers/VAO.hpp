#pragma once

#include <vector>

#include <glad/glad.h>

#include "VBO.hpp"

namespace ft {

    class VAO
    {
    private:
        unsigned int _id;
        std::vector<VBO*> _vbos;
    public:
        VAO();
        ~VAO();

        void Bind();
        void Unbind();

        void AddVBO(VBO& vbo);
    };

}
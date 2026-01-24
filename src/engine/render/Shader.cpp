#pragma once

#include "Shader.hpp"

namespace ft{

    Shader::Shader(const ShaderSource& src)
        : _src(src)
    {
        _id = glCreateProgram();
        /* Vertex Shader */
        unsigned int v_sh;
        v_sh = CreateShader(src.vertex, GL_VERTEX_SHADER);
        glAttachShader(_id, v_sh);
        glDeleteShader(v_sh);
        /* Fragment Shader */
        unsigned int f_sh;
        f_sh = CreateShader(src.fragment, GL_FRAGMENT_SHADER);
        glAttachShader(_id, f_sh);
        glDeleteShader(f_sh);

        glLinkProgram(_id);
    }

    Shader::~Shader()
    {
        glDeleteProgram(_id);
    }

    unsigned int Shader::CreateShader(const std::string& src, unsigned int type)
    {
        const char* c_src = src.c_str();
        unsigned int id = glCreateShader(type);
        glShaderSource(id, 1, &c_src, 0);
        glCompileShader(id);
        return (id);
    }

    void Shader::Bind()
    {
        glUseProgram(_id);
    }

    void Shader::Unbind()
    {
        glUseProgram(0);
    }

}
#pragma once

#include <string>
#include <fstream>
#include <sstream>

#include <glad/glad.h>

namespace ft {

    struct ShaderSource
    {
        std::string vertex;
        std::string fragment;
    };

    class Shader
    {
    private:
        unsigned int _id;
        ShaderSource _src;
    public:
        Shader(const ShaderSource& src);
        ~Shader();

        void Bind();
        void Unbind();
    private:
        Shader(const Shader& o);
        Shader& operator=(const Shader& o);
        unsigned int CreateShader(const std::string& src, unsigned int type);
    };

    /* TODO: this should be the job of a resource manager */
    static ShaderSource read_shader_file(const std::string& path)
    {
        ShaderSource src;
        std::fstream file(path);
        std::string line;
        std::string* current_shader = &src.vertex;

        while (std::getline(file, line))
        {
            if (!line.find(".vertex"))
                current_shader = &src.vertex;
            else if (!line.find(".fragment"))
                current_shader = &src.fragment;
            else
                *current_shader += (line + "\n");
        }
        file.close();
        return (src);
    }

}
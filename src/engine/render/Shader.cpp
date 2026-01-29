#include "Shader.hpp"

namespace ft{

    Shader::Shader(const std::string& v_src, const std::string& f_src)
    {
        _id = glCreateProgram();
        /* Vertex Shader */
        unsigned int v_sh;
        v_sh = CreateShader(v_src, GL_VERTEX_SHADER);
        glAttachShader(_id, v_sh);
        glDeleteShader(v_sh);
        /* Fragment Shader */
        unsigned int f_sh;
        f_sh = CreateShader(f_src, GL_FRAGMENT_SHADER);
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

    void Shader::SetUniform(const std::string& name, const glm::mat4& v1) const
    {
        unsigned int loc = glGetUniformLocation(_id, name.c_str());
        glProgramUniformMatrix4fv(_id, loc, 1, GL_FALSE, glm::value_ptr(v1));
    }

    void Shader::SetUniform(const std::string& name, const glm::vec2& v1) const
    {
        unsigned int loc = glGetUniformLocation(_id, name.c_str());
        glProgramUniform2fv(_id, loc, 1, glm::value_ptr(v1));
    }

    void Shader::SetUniform(const std::string& name, const glm::vec3& v1) const
    {
        unsigned int loc = glGetUniformLocation(_id, name.c_str());
        glProgramUniform3fv(_id, loc, 1, glm::value_ptr(v1));
    }

    void Shader::SetUniform(const std::string& name, const glm::vec4& v1) const
    {
        unsigned int loc = glGetUniformLocation(_id, name.c_str());
        glProgramUniform4fv(_id, loc, 1, glm::value_ptr(v1));
    }

    void Shader::SetUniform(const std::string& name, const float& v1) const
    {
        unsigned int loc = glGetUniformLocation(_id, name.c_str());
        glProgramUniform1f(_id, loc, v1);
    }

    void Shader::SetUniform(const std::string& name, const int& v1) const
    {
        unsigned int loc = glGetUniformLocation(_id, name.c_str());
        glProgramUniform1i(_id, loc, v1);
    }

    void Shader::SetUniform(const std::string& name, const bool& v1) const
    {
        unsigned int loc = glGetUniformLocation(_id, name.c_str());
        glProgramUniform1i(_id, loc, v1);
    }


}
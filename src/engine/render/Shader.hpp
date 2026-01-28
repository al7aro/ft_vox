#pragma once

#include <string>
#include <fstream>
#include <sstream>

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace ft {

    class Shader
    {
    private:
        unsigned int _id;
    public:
        Shader(const std::string& v_src, const std::string& f_sh);
        ~Shader();

        void Bind();
        void Unbind();

        void SetUniform(const std::string& name, const glm::mat4& v1) const;
        void SetUniform(const std::string& name, const glm::vec2& v1) const;
        void SetUniform(const std::string& name, const glm::vec3& v1) const;
        void SetUniform(const std::string& name, const glm::vec4& v1) const;
        void SetUniform(const std::string& name, const float& v1) const;
        void SetUniform(const std::string& name, const int& v1) const;
        void SetUniform(const std::string& name, const bool& v1) const;

        inline unsigned int GetId() const { return (_id); }

    private:
        Shader(const Shader& o);
        Shader& operator=(const Shader& o);
        unsigned int CreateShader(const std::string& src, unsigned int type);
    };

}
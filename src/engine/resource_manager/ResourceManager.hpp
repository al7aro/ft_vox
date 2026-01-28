#pragma once

#include <vector>
#include <map>
#include <memory>

#include "../render/Shader.hpp"
#include "../render/Material.hpp"
#include "../render/Texture2DArray.hpp"
#include "Resources.hpp"

namespace ft {

    class ResourceManager
    {
    private:
        std::map<unsigned int, std::shared_ptr<Shader> > _shaders;
        std::map<unsigned int, std::shared_ptr<Texture2DArray> > _texures;
        std::vector<std::shared_ptr<Material> > _materials;
    public:
        ResourceManager();
        ~ResourceManager();

        /* SHADER */
        unsigned int CreateShader(const std::string& sh_path);
        std::shared_ptr<Shader> GetShader(unsigned int id) const;
        static ShaderSource read_shader_file(const std::string& path);

        /* TEXTURE */
        glm::ivec2 CreateTexture(const std::string& tex_path);
        std::shared_ptr<Texture2DArray> GetTexture(const glm::ivec2& id) const;
        std::shared_ptr<Texture2DArray> GetTexture(unsigned int mat_id, unsigned int type = 0) const;
        static TextureSource read_image_file(const std::string& path);
        
        /* MATERIAL */
        unsigned int CreateMaterial(const glm::vec4& color, const glm::ivec2& texture_id);
        unsigned int CreateMaterial(const glm::vec4& color, const std::string& tex_path);
        void AddMaterialProperty(unsigned int mat_id, Material::MaterialProperty type, const glm::vec3 value);
        void AddMaterialProperty(unsigned int mat_id, Material::MaterialProperty type, float value);
        void AddMaterialProperty(unsigned int mat_id, Material::MaterialProperty type, glm::ivec2 value);
        void AddMaterialProperty(unsigned int mat_id, Material::MaterialProperty type, const std::string& value);
        std::shared_ptr<Material> GetMaterial(unsigned int id) const;

    };

}
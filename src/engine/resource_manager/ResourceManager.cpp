#include "ResourceManager.hpp"

namespace ft {

    ResourceManager::ResourceManager() {}
    ResourceManager::~ResourceManager() {}

    unsigned int ResourceManager::CreateShader(const std::string& sh_path)
    {
        ShaderSource src = read_shader_file(sh_path);
        std::shared_ptr<Shader> sh = std::make_shared<Shader>(src.vertex, src.fragment);
        // TODO: check for duplicates
        _shaders[sh->GetId()] = sh;
        return (sh->GetId());
    }

    glm::ivec2 ResourceManager::CreateTexture(const std::string& tex_path)
    {
        TextureSource src = read_image_file(tex_path);
        std::shared_ptr<Texture2DArray> tex;
        if (_texures.empty())
            tex = std::make_shared<Texture2DArray>(src.width, src.height);
        else
            tex = _texures.begin()->second;
        // TODO: check for duplicates
        unsigned int layer = tex->AddTexture(src.data, src.width, src.height);
        _texures[tex->GetId()] = tex;
        return (glm::ivec2(tex->GetId(), layer));
    }

    unsigned int ResourceManager::CreateMaterial(const glm::vec4& color, const glm::ivec2& texture_id)
    {
        std::shared_ptr<Material> mat = std::make_shared<Material>();
        mat->Ka = color;
        mat->diffuse_map_id= texture_id;
        _materials.push_back(mat);
        return (_materials.size() - 1);
    }

    unsigned int ResourceManager::CreateMaterial(const glm::vec4& color, const std::string& tex_path)
    {
        std::shared_ptr<Material> mat = std::make_shared<Material>();
        mat->Ka = color;
        mat->diffuse_map_id= CreateTexture(tex_path);
        _materials.push_back(mat);
        return (_materials.size() - 1);
    }

    std::shared_ptr<Shader> ResourceManager::GetShader(unsigned int id) const
    {
        auto ret = _shaders.find(id);
        if (ret != _shaders.end())
            return (ret->second);
        return (std::shared_ptr<Shader>());
    }

    std::shared_ptr<Texture2DArray> ResourceManager::GetTexture(const glm::ivec2& id) const
    {
        auto ret = _texures.find(id[0]);
        if (ret != _texures.end())
            return (ret->second);
        return (std::shared_ptr<Texture2DArray>());
    }

    std::shared_ptr<Texture2DArray> ResourceManager::GetTexture(unsigned int mat_id, unsigned int type) const
    {
        std::shared_ptr<Material> mat = GetMaterial(mat_id);
        return (GetTexture(mat->diffuse_map_id));
    }

    std::shared_ptr<Material> ResourceManager::GetMaterial(unsigned int id) const
    {
        for (int i = 0; i < _materials.size(); i++)
        {
            if (i == id)
                return (_materials[i]);
        }
        return (std::shared_ptr<Material>());
    }

    void ResourceManager::AddMaterialProperty(unsigned int mat_id, Material::MaterialProperty type, const glm::vec3 value)
    {
        std::shared_ptr<Material> mat = GetMaterial(mat_id);
        if (!mat) return;
        switch (type)
        {
        case Material::KA:
            mat->Ka = value; break;
        case Material::KS:
            mat->Ks = value; break;
        case Material::KD:
            mat->Kd = value; break;
        }
    }
    void ResourceManager::AddMaterialProperty(unsigned int mat_id, Material::MaterialProperty type, float value)
    {
        std::shared_ptr<Material> mat = GetMaterial(mat_id);
        if (!mat) return;
        mat->d = value;
    }
    void ResourceManager::AddMaterialProperty(unsigned int mat_id, Material::MaterialProperty type, glm::ivec2 value)
    {
        std::shared_ptr<Material> mat = GetMaterial(mat_id);
        if (!mat) return;
        switch (type)
        {
        case Material::DIFFUSE_MAP:
            mat->diffuse_map_id = value; break;
        case Material::SPECULAR_MAP:
            mat->specular_map_id = value; break;
        case Material::BUMP_MAP:
            mat->bump_map_id = value; break;
        }
    }
    void ResourceManager::AddMaterialProperty(unsigned int mat_id, Material::MaterialProperty type, const std::string& value)
    {
        std::shared_ptr<Material> mat = GetMaterial(mat_id);
        if (!mat) return;
        switch (type)
        {
        case Material::DIFFUSE_MAP:
            mat->diffuse_map_id = CreateTexture(value); break;
        case Material::SPECULAR_MAP:
            mat->specular_map_id = CreateTexture(value); break;
        case Material::BUMP_MAP:
            mat->bump_map_id = CreateTexture(value); break;
        }
    }

    ShaderSource ResourceManager::read_shader_file(const std::string& path)
    {
        ShaderSource src;
        src.filename = path;
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

    TextureSource ResourceManager::read_image_file(const std::string& path)
    {
        TextureSource src;
        src.filename = path;
        src.data = stbi_load(path.c_str(), &src.width, &src.height, &src.chn, 4);
        return (src);
    }
}
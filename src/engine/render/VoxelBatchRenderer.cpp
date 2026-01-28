#include "VoxelBatchRenderer.hpp"

namespace ft {

    VoxelBatchRenderer::VoxelBatchRenderer()
        : _vao(), _vbo(MAX_BATCH_SIZE), _batch_cnt(0), _vertex_cnt(0)
    {
        _vao.AddVBO(_vbo);
    }

    VoxelBatchRenderer::~VoxelBatchRenderer() {}

    void VoxelBatchRenderer::Begin(const RenderData& data)
    {
        if (data.shader)
        {
            data.shader->Bind();
            data.shader->SetUniform("u_texture", 0);
            for (int i = 0; i < data.materials.size(); i++)
            {
                data.shader->SetUniform("u_material[" + std::to_string(i) + "].Ka", data.materials[i]->Ka);
                data.shader->SetUniform("u_material[" + std::to_string(i) + "].Kd", data.materials[i]->Kd);
                data.shader->SetUniform("u_material[" + std::to_string(i) + "].Ks", data.materials[i]->Ks);
                data.shader->SetUniform("u_material[" + std::to_string(i) + "].d", data.materials[i]->d);
                data.shader->SetUniform("u_material[" + std::to_string(i) + "].diffuse_map_id", data.materials[i]->diffuse_map_id);
            }
        }
        if (data.textures)
            data.textures->BindTextureUnit(0);
        _batch_cnt = 0;
    }

    void VoxelBatchRenderer::DrawVoxel(const glm::vec3 pos, int material_id)
    {
        std::vector<Vertex> cube = cube_geometry(pos, material_id);
        unsigned int cube_vertices = cube.size();
        if (sizeof(Vertex) * (_vertex_cnt + cube_vertices) >= MAX_BATCH_SIZE)
            Flush();
        _vbo.AddData(cube);
        _vertex_cnt += cube_vertices;
    }

    void VoxelBatchRenderer::End()
    {
        Flush();
    }

    void VoxelBatchRenderer::Flush()
    {
        _vao.Bind();
        glDrawArrays(GL_TRIANGLES, 0, _vertex_cnt);
        
        /* CLEAR */
        _batch_cnt++;
        _vertex_cnt = 0;
        _vbo.Clear();
    }

    unsigned int VoxelBatchRenderer::GetBatchCount() const
    {
        return (_batch_cnt);
    }

    //unsigned int VoxelBatchRenderer::AddTextureArray(int width, int height, int depth)
    //{
    //    _texture_array = std::make_shared<Texture2DArray>(width, height, depth);
    //    return (0);
    //}

    //unsigned int VoxelBatchRenderer::AddMaterial(const glm::vec4& color, const TextureSource& tex_src)
    //{
    //    glm::ivec2 texture_id(0, 0);
    //    if (!_texture_array)
    //        _texture_array = std::make_shared<Texture2DArray>(tex_src.width, tex_src.height);
    //    else
    //        texture_id.y = _texture_array->AddTexture(tex_src.data, tex_src.width, tex_src.height);
    //    _materials.push_back(Material{color, texture_id});
    //    return (_materials.size() - 1);
    //}

}
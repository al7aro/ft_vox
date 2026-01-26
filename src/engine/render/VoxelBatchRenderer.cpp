#include "VoxelBatchRenderer.hpp"

namespace ft {

    VoxelBatchRenderer::VoxelBatchRenderer()
        : _vao(), _vbo(MAX_BATCH_SIZE), _current_shader(nullptr), _batch_cnt(0), _vertex_cnt(0)
    {
        _vao.AddVBO(_vbo);
    }

    VoxelBatchRenderer::~VoxelBatchRenderer() {}

    void VoxelBatchRenderer::Begin(std::shared_ptr<Shader> shader)
    {
        _current_shader = shader;
        _batch_cnt = 0;
    }

    void VoxelBatchRenderer::DrawVoxel(const glm::vec3 pos, glm::vec4 col)
    {
        std::vector<Vertex> cube = cube_geometry(pos, col);
        unsigned int cube_vertices = cube.size();
        size_t l1 = sizeof(Vertex) * (_vertex_cnt + cube_vertices);
        size_t l2 = MAX_BATCH_SIZE;
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
        if (_current_shader)
            _current_shader->Bind();
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

}
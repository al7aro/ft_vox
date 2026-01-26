#pragma once

#include <memory>

#include <glm/glm.hpp>

#include "buffers/Vertex.hpp"
#include "buffers/VAO.hpp"
#include "buffers/VBO.hpp"
#include "Shader.hpp"
#include "Cube.hpp"

#define MAX_BATCH_SIZE sizeof(Vertex) * 36 * 1000 /* 100 CUBES */

namespace ft {

    class VoxelBatchRenderer
    {
    private:
        VAO _vao;
        VBO _vbo;
        std::shared_ptr<Shader> _current_shader;
        unsigned int _batch_cnt;
        unsigned int _vertex_cnt;

    public:
        VoxelBatchRenderer();
        ~VoxelBatchRenderer();

        void Begin(std::shared_ptr<Shader> shader);
        void End();

        void Flush();

        void DrawVoxel(const glm::vec3 pos, glm::vec4 col);

        unsigned int GetBatchCount() const;
    };

}
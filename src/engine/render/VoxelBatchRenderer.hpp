#pragma once

#include <memory>
#include <vector>

#include <glm/glm.hpp>

#include "buffers/Vertex.hpp"
#include "buffers/VAO.hpp"
#include "buffers/VBO.hpp"
#include "Shader.hpp"
#include "camera/FPSCamera.hpp"
#include "Material.hpp"
#include "Texture2DArray.hpp"
#include "../resource_manager/Cube.hpp"
#include "../resource_manager/Resources.hpp"

#define MAX_BATCH_SIZE sizeof(Vertex) * 36 * 1000 /* 100 CUBES */

namespace ft {

    struct RenderData
    {
        std::shared_ptr<Shader> shader;
        std::shared_ptr<Texture2DArray> textures;
        std::vector<std::shared_ptr<Material> > materials;
    };

    class VoxelBatchRenderer
    {
    private:
        VAO _vao;
        VBO _vbo;
        unsigned int _batch_cnt;
        unsigned int _vertex_cnt;

    public:
        VoxelBatchRenderer();
        ~VoxelBatchRenderer();

        void Begin(const RenderData& data);
        void End();

        void Flush();

        void DrawVoxel(const glm::vec3 pos, int material_id = -1);

        unsigned int GetBatchCount() const;
    };

}
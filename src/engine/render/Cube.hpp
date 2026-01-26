#pragma once

namespace ft {

    static inline std::vector<Vertex> cube_geometry(const glm::vec3& pos, const glm::vec4& color = glm::vec4(1.0))
    {
        std::vector<Vertex> cube = {
            // --- Front Face (Normal +Z) ---
            Vertex{{pos.x - 0.5f, pos.y - 0.5f, pos.z + 0.5f}, {0.0f, 0.0f}, color, { 0.0f,  0.0f,  1.0f}},
            Vertex{{pos.x + 0.5f, pos.y - 0.5f, pos.z + 0.5f}, {1.0f, 0.0f}, color, { 0.0f,  0.0f,  1.0f}},
            Vertex{{pos.x + 0.5f, pos.y + 0.5f, pos.z + 0.5f}, {1.0f, 1.0f}, color, { 0.0f,  0.0f,  1.0f}},
            Vertex{{pos.x + 0.5f, pos.y + 0.5f, pos.z + 0.5f}, {1.0f, 1.0f}, color, { 0.0f,  0.0f,  1.0f}},
            Vertex{{pos.x - 0.5f, pos.y + 0.5f, pos.z + 0.5f}, {0.0f, 1.0f}, color, { 0.0f,  0.0f,  1.0f}},
            Vertex{{pos.x - 0.5f, pos.y - 0.5f, pos.z + 0.5f}, {0.0f, 0.0f}, color, { 0.0f,  0.0f,  1.0f}},

            // --- Back Face (Normal -Z) ---
            Vertex{{pos.x + 0.5f, pos.y - 0.5f, pos.z - 0.5f}, {0.0f, 0.0f}, color, { 0.0f,  0.0f, -1.0f}},
            Vertex{{pos.x - 0.5f, pos.y - 0.5f, pos.z - 0.5f}, {1.0f, 0.0f}, color, { 0.0f,  0.0f, -1.0f}},
            Vertex{{pos.x - 0.5f, pos.y + 0.5f, pos.z - 0.5f}, {1.0f, 1.0f}, color, { 0.0f,  0.0f, -1.0f}},
            Vertex{{pos.x - 0.5f, pos.y + 0.5f, pos.z - 0.5f}, {1.0f, 1.0f}, color, { 0.0f,  0.0f, -1.0f}},
            Vertex{{pos.x + 0.5f, pos.y + 0.5f, pos.z - 0.5f}, {0.0f, 1.0f}, color, { 0.0f,  0.0f, -1.0f}},
            Vertex{{pos.x + 0.5f, pos.y - 0.5f, pos.z - 0.5f}, {0.0f, 0.0f}, color, { 0.0f,  0.0f, -1.0f}},

            // --- Left Face (Normal -X) ---
            Vertex{{pos.x - 0.5f, pos.y - 0.5f, pos.z - 0.5f}, {0.0f, 0.0f}, color, {-1.0f,  0.0f,  0.0f}},
            Vertex{{pos.x - 0.5f, pos.y - 0.5f, pos.z + 0.5f}, {1.0f, 0.0f}, color, {-1.0f,  0.0f,  0.0f}},
            Vertex{{pos.x - 0.5f, pos.y + 0.5f, pos.z + 0.5f}, {1.0f, 1.0f}, color, {-1.0f,  0.0f,  0.0f}},
            Vertex{{pos.x - 0.5f, pos.y + 0.5f, pos.z + 0.5f}, {1.0f, 1.0f}, color, {-1.0f,  0.0f,  0.0f}},
            Vertex{{pos.x - 0.5f, pos.y + 0.5f, pos.z - 0.5f}, {0.0f, 1.0f}, color, {-1.0f,  0.0f,  0.0f}},
            Vertex{{pos.x - 0.5f, pos.y - 0.5f, pos.z - 0.5f}, {0.0f, 0.0f}, color, {-1.0f,  0.0f,  0.0f}},

            // --- Right Face (Normal +X) ---
            Vertex{{pos.x + 0.5f, pos.y - 0.5f, pos.z + 0.5f}, {0.0f, 0.0f}, color, { 1.0f,  0.0f,  0.0f}},
            Vertex{{pos.x + 0.5f, pos.y - 0.5f, pos.z - 0.5f}, {1.0f, 0.0f}, color, { 1.0f,  0.0f,  0.0f}},
            Vertex{{pos.x + 0.5f, pos.y + 0.5f, pos.z - 0.5f}, {1.0f, 1.0f}, color, { 1.0f,  0.0f,  0.0f}},
            Vertex{{pos.x + 0.5f, pos.y + 0.5f, pos.z - 0.5f}, {1.0f, 1.0f}, color, { 1.0f,  0.0f,  0.0f}},
            Vertex{{pos.x + 0.5f, pos.y + 0.5f, pos.z + 0.5f}, {0.0f, 1.0f}, color, { 1.0f,  0.0f,  0.0f}},
            Vertex{{pos.x + 0.5f, pos.y - 0.5f, pos.z + 0.5f}, {0.0f, 0.0f}, color, { 1.0f,  0.0f,  0.0f}},

            // --- Top Face (Normal +Y) ---
            Vertex{{pos.x - 0.5f, pos.y + 0.5f, pos.z + 0.5f}, {0.0f, 0.0f}, color, { 0.0f,  1.0f,  0.0f}},
            Vertex{{pos.x + 0.5f, pos.y + 0.5f, pos.z + 0.5f}, {1.0f, 0.0f}, color, { 0.0f,  1.0f,  0.0f}},
            Vertex{{pos.x + 0.5f, pos.y + 0.5f, pos.z - 0.5f}, {1.0f, 1.0f}, color, { 0.0f,  1.0f,  0.0f}},
            Vertex{{pos.x + 0.5f, pos.y + 0.5f, pos.z - 0.5f}, {1.0f, 1.0f}, color, { 0.0f,  1.0f,  0.0f}},
            Vertex{{pos.x - 0.5f, pos.y + 0.5f, pos.z - 0.5f}, {0.0f, 1.0f}, color, { 0.0f,  1.0f,  0.0f}},
            Vertex{{pos.x - 0.5f, pos.y + 0.5f, pos.z + 0.5f}, {0.0f, 0.0f}, color, { 0.0f,  1.0f,  0.0f}},

            // --- Bottom Face (Normal -Y) ---
            Vertex{{pos.x - 0.5f, pos.y - 0.5f, pos.z - 0.5f}, {0.0f, 0.0f}, color, { 0.0f, -1.0f,  0.0f}},
            Vertex{{pos.x + 0.5f, pos.y - 0.5f, pos.z - 0.5f}, {1.0f, 0.0f}, color, { 0.0f, -1.0f,  0.0f}},
            Vertex{{pos.x + 0.5f, pos.y - 0.5f, pos.z + 0.5f}, {1.0f, 1.0f}, color, { 0.0f, -1.0f,  0.0f}},
            Vertex{{pos.x + 0.5f, pos.y - 0.5f, pos.z + 0.5f}, {1.0f, 1.0f}, color, { 0.0f, -1.0f,  0.0f}},
            Vertex{{pos.x - 0.5f, pos.y - 0.5f, pos.z + 0.5f}, {0.0f, 1.0f}, color, { 0.0f, -1.0f,  0.0f}},
            Vertex{{pos.x - 0.5f, pos.y - 0.5f, pos.z - 0.5f}, {0.0f, 0.0f}, color, { 0.0f, -1.0f,  0.0f}},
        };
        return (cube);
    }

}
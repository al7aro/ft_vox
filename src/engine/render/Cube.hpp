#pragma once

namespace ft {

    static inline std::vector<Vertex> cube_geometry(const glm::vec3& pos, float material_id)
    {
        float w = 1.0f / 4.0f;
        float h = 1.0f / 3.0f;
        glm::vec4 color(1.0);
        std::vector<Vertex> cube = {
            // --- Front Face (+Z) (Row 1, Col 1) ---
            Vertex{{pos.x - 0.5f, pos.y - 0.5f, pos.z + 0.5f}, {1*w, 1*h}, color, { 0.0f,  0.0f,  1.0f}, {material_id}}, // BL
            Vertex{{pos.x + 0.5f, pos.y - 0.5f, pos.z + 0.5f}, {2*w, 1*h}, color, { 0.0f,  0.0f,  1.0f}, {material_id}}, // BR
            Vertex{{pos.x + 0.5f, pos.y + 0.5f, pos.z + 0.5f}, {2*w, 2*h}, color, { 0.0f,  0.0f,  1.0f}, {material_id}}, // TR
            Vertex{{pos.x + 0.5f, pos.y + 0.5f, pos.z + 0.5f}, {2*w, 2*h}, color, { 0.0f,  0.0f,  1.0f}, {material_id}}, // TR
            Vertex{{pos.x - 0.5f, pos.y + 0.5f, pos.z + 0.5f}, {1*w, 2*h}, color, { 0.0f,  0.0f,  1.0f}, {material_id}}, // TL
            Vertex{{pos.x - 0.5f, pos.y - 0.5f, pos.z + 0.5f}, {1*w, 1*h}, color, { 0.0f,  0.0f,  1.0f}, {material_id}}, // BL

            // --- Back Face (-Z) (Row 1, Col 3) ---
            Vertex{{pos.x + 0.5f, pos.y - 0.5f, pos.z - 0.5f}, {3*w, 1*h}, color, { 0.0f,  0.0f, -1.0f}, {material_id}}, // BL
            Vertex{{pos.x - 0.5f, pos.y - 0.5f, pos.z - 0.5f}, {4*w, 1*h}, color, { 0.0f,  0.0f, -1.0f}, {material_id}}, // BR
            Vertex{{pos.x - 0.5f, pos.y + 0.5f, pos.z - 0.5f}, {4*w, 2*h}, color, { 0.0f,  0.0f, -1.0f}, {material_id}}, // TR
            Vertex{{pos.x - 0.5f, pos.y + 0.5f, pos.z - 0.5f}, {4*w, 2*h}, color, { 0.0f,  0.0f, -1.0f}, {material_id}}, // TR
            Vertex{{pos.x + 0.5f, pos.y + 0.5f, pos.z - 0.5f}, {3*w, 2*h}, color, { 0.0f,  0.0f, -1.0f}, {material_id}}, // TL
            Vertex{{pos.x + 0.5f, pos.y - 0.5f, pos.z - 0.5f}, {3*w, 1*h}, color, { 0.0f,  0.0f, -1.0f}, {material_id}}, // BL

            // --- Left Face (-X) (Row 1, Col 0) ---
            Vertex{{pos.x - 0.5f, pos.y - 0.5f, pos.z - 0.5f}, {0*w, 1*h}, color, {-1.0f,  0.0f,  0.0f}, {material_id}}, // BL
            Vertex{{pos.x - 0.5f, pos.y - 0.5f, pos.z + 0.5f}, {1*w, 1*h}, color, {-1.0f,  0.0f,  0.0f}, {material_id}}, // BR
            Vertex{{pos.x - 0.5f, pos.y + 0.5f, pos.z + 0.5f}, {1*w, 2*h}, color, {-1.0f,  0.0f,  0.0f}, {material_id}}, // TR
            Vertex{{pos.x - 0.5f, pos.y + 0.5f, pos.z + 0.5f}, {1*w, 2*h}, color, {-1.0f,  0.0f,  0.0f}, {material_id}}, // TR
            Vertex{{pos.x - 0.5f, pos.y + 0.5f, pos.z - 0.5f}, {0*w, 2*h}, color, {-1.0f,  0.0f,  0.0f}, {material_id}}, // TL
            Vertex{{pos.x - 0.5f, pos.y - 0.5f, pos.z - 0.5f}, {0*w, 1*h}, color, {-1.0f,  0.0f,  0.0f}, {material_id}}, // BL

            // --- Right Face (+X) (Row 1, Col 2) ---
            Vertex{{pos.x + 0.5f, pos.y - 0.5f, pos.z + 0.5f}, {2*w, 1*h}, color, { 1.0f,  0.0f,  0.0f}, {material_id}}, // BL
            Vertex{{pos.x + 0.5f, pos.y - 0.5f, pos.z - 0.5f}, {3*w, 1*h}, color, { 1.0f,  0.0f,  0.0f}, {material_id}}, // BR
            Vertex{{pos.x + 0.5f, pos.y + 0.5f, pos.z - 0.5f}, {3*w, 2*h}, color, { 1.0f,  0.0f,  0.0f}, {material_id}}, // TR
            Vertex{{pos.x + 0.5f, pos.y + 0.5f, pos.z - 0.5f}, {3*w, 2*h}, color, { 1.0f,  0.0f,  0.0f}, {material_id}}, // TR
            Vertex{{pos.x + 0.5f, pos.y + 0.5f, pos.z + 0.5f}, {2*w, 2*h}, color, { 1.0f,  0.0f,  0.0f}, {material_id}}, // TL
            Vertex{{pos.x + 0.5f, pos.y - 0.5f, pos.z + 0.5f}, {2*w, 1*h}, color, { 1.0f,  0.0f,  0.0f}, {material_id}}, // BL

            // --- Top Face (+Y) (Row 2, Col 1) ---
            // Note: Row 2 is the top row in UV space (OpenGL UVs start at bottom)
            Vertex{{pos.x - 0.5f, pos.y + 0.5f, pos.z + 0.5f}, {1*w, 2*h}, color, { 0.0f,  1.0f,  0.0f}, {material_id}}, // BL
            Vertex{{pos.x + 0.5f, pos.y + 0.5f, pos.z + 0.5f}, {2*w, 2*h}, color, { 0.0f,  1.0f,  0.0f}, {material_id}}, // BR
            Vertex{{pos.x + 0.5f, pos.y + 0.5f, pos.z - 0.5f}, {2*w, 3*h}, color, { 0.0f,  1.0f,  0.0f}, {material_id}}, // TR
            Vertex{{pos.x + 0.5f, pos.y + 0.5f, pos.z - 0.5f}, {2*w, 3*h}, color, { 0.0f,  1.0f,  0.0f}, {material_id}}, // TR
            Vertex{{pos.x - 0.5f, pos.y + 0.5f, pos.z - 0.5f}, {1*w, 3*h}, color, { 0.0f,  1.0f,  0.0f}, {material_id}}, // TL
            Vertex{{pos.x - 0.5f, pos.y + 0.5f, pos.z + 0.5f}, {1*w, 2*h}, color, { 0.0f,  1.0f,  0.0f}, {material_id}}, // BL

            // --- Bottom Face (-Y) (Row 0, Col 1) ---
            Vertex{{pos.x - 0.5f, pos.y - 0.5f, pos.z - 0.5f}, {1*w, 0*h}, color, { 0.0f, -1.0f,  0.0f}, {material_id}}, // BL
            Vertex{{pos.x + 0.5f, pos.y - 0.5f, pos.z - 0.5f}, {2*w, 0*h}, color, { 0.0f, -1.0f,  0.0f}, {material_id}}, // BR
            Vertex{{pos.x + 0.5f, pos.y - 0.5f, pos.z + 0.5f}, {2*w, 1*h}, color, { 0.0f, -1.0f,  0.0f}, {material_id}}, // TR
            Vertex{{pos.x + 0.5f, pos.y - 0.5f, pos.z + 0.5f}, {2*w, 1*h}, color, { 0.0f, -1.0f,  0.0f}, {material_id}}, // TR
            Vertex{{pos.x - 0.5f, pos.y - 0.5f, pos.z + 0.5f}, {1*w, 1*h}, color, { 0.0f, -1.0f,  0.0f}, {material_id}}, // TL
            Vertex{{pos.x - 0.5f, pos.y - 0.5f, pos.z - 0.5f}, {1*w, 0*h}, color, { 0.0f, -1.0f,  0.0f}, {material_id}}, // BL
        };
        return (cube);
    }

}
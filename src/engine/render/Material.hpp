#pragma once

#include <glm/glm.hpp>

namespace ft {

    struct Material
    {
        enum MaterialProperty
        {
            KA = 0,
            KD, KS,
            D,
            DIFFUSE_MAP,
            SPECULAR_MAP,
            BUMP_MAP
        };

        glm::vec3 Ka = glm::vec3(1.0);  /* ambient */
        glm::vec3 Kd = glm::vec3(1.0);  /* diffuse */
        glm::vec3 Ks = glm::vec3(1.0);  /* specular */
        float d = 1.0;                  /* shinyness */

        /* TEXTURES */
        glm::ivec2 diffuse_map_id = glm::ivec2(-1);
        glm::ivec2 specular_map_id = glm::ivec2(-1);
        glm::ivec2 bump_map_id = glm::ivec2(-1);
    };

}
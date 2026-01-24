#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace ft {

    struct Vertex
    {
        glm::vec3 position;
        glm::vec2 tex_coord;
        glm::vec4 color;
        glm::vec3 normal;
    };

}
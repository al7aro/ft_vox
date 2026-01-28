#pragma once

#include <string>

namespace ft {

    struct ShaderSource
    {
        std::string filename;
        std::string vertex;
        std::string fragment;
    };

    struct TextureSource
    {
        std::string filename;
        void* data;
        int width, height, chn;
    };

}
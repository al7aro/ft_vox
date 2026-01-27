#pragma once

#include <string>

#include <glad/glad.h>
#include <stb_image.h>

namespace ft {

    struct TextureSource
    {
        void* data;
        int width, height, chn;
    };

    class Texture2D
    {
    private:
        unsigned int _id;
    public:
        Texture2D(const TextureSource& src);
        ~Texture2D();

        void Bind(unsigned int texture_unit = 0) const;
    };

    /* TODO: this should be the job of a resource manager */
    static TextureSource read_image_file(const std::string& path)
    {
        TextureSource src;
        src.data = stbi_load(path.c_str(), &src.width, &src.height, &src.chn, 4);
        return (src);
    }

}
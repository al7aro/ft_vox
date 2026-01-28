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

    class Texture2DArray
    {
    private:
        unsigned int _id;
        int _current_depth;
        const int _WIDTH, _HEIGHT, _DEPTH;
    public:
        Texture2DArray(int width, int height, int depth = 8);
        ~Texture2DArray();

        int AddTexture(const TextureSource& src);

        void BindTextureUnit(unsigned int texture_unit = 0) const;

        inline int GetWidth() const { return (_WIDTH); }
        inline int GetHeight() const { return (_HEIGHT); }
        inline int GetDepth() const { return (_DEPTH); }
    };

    /* TODO: this should be the job of a resource manager */
    static TextureSource read_image_file(const std::string& path)
    {
        TextureSource src;
        src.data = stbi_load(path.c_str(), &src.width, &src.height, &src.chn, 4);
        return (src);
    }

}
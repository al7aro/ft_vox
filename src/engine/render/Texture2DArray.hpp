#pragma once

#include <string>

#include <glad/glad.h>
#include <stb_image.h>

namespace ft {

    class Texture2DArray
    {
    private:
        unsigned int _id;
        int _current_depth;
        const int _WIDTH, _HEIGHT, _DEPTH;
    public:
        Texture2DArray(int width, int height, int depth = 8);
        ~Texture2DArray();

        int AddTexture(void* data, int width, int height);

        void BindTextureUnit(unsigned int texture_unit = 0) const;

        inline int GetWidth() const { return (_WIDTH); }
        inline int GetHeight() const { return (_HEIGHT); }
        inline int GetDepth() const { return (_DEPTH); }

        inline unsigned int GetId() const { return (_id); }
    };

}
#include "Texture2DArray.hpp"

namespace ft {

    Texture2DArray::Texture2DArray(int width, int height, int depth)
        : _WIDTH(width), _HEIGHT(height), _DEPTH(depth), _current_depth(0)
    {
        glCreateTextures(GL_TEXTURE_2D_ARRAY, 1, &_id);

        glTextureParameteri(_id, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTextureParameteri(_id, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTextureParameteri(_id, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTextureParameteri(_id, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

        glTextureStorage3D(_id, 4, GL_RGBA8, width, height, depth);
    }

    Texture2DArray::~Texture2DArray() {}

    int Texture2DArray::AddTexture(void* data, int width, int height)
    {
        if (_current_depth >= _DEPTH)
            return (-1);
        if (width != _WIDTH || height != _HEIGHT)
            return (-1);
        glTextureSubImage3D(_id, 0, 0, 0, _current_depth, _WIDTH, _HEIGHT, 1, GL_RGBA, GL_UNSIGNED_BYTE, data);
        //glGenerateTextureMipmap(_id);
        _current_depth++;
        return (_current_depth - 1);
    }

    void Texture2DArray::BindTextureUnit(unsigned int texture_unit) const
    {
        glBindTextureUnit(texture_unit, _id);
    }

}
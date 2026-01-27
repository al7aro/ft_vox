#include "Texture2D.hpp"

namespace ft {

    Texture2D::Texture2D(const TextureSource& src)
    {
        glCreateTextures(GL_TEXTURE_2D, 1, &_id);
        glTextureParameteri(_id, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTextureParameteri(_id, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTextureParameteri(_id, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTextureParameteri(_id, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
        glTextureStorage2D(_id, 4, GL_RGBA8, src.width, src.height);
        glTextureSubImage2D(_id, 0, 0, 0, src.width, src.height, GL_RGBA, GL_UNSIGNED_BYTE, src.data);
        glGenerateTextureMipmap(_id);
    }

    Texture2D::~Texture2D() {}

    void Texture2D::Bind(unsigned int texture_unit) const
    {
        glActiveTexture(GL_TEXTURE0 + texture_unit);
        glBindTexture(GL_TEXTURE_2D, _id);
    }

}
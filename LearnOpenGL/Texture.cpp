#include <glad/glad.h>
#include "Texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include <string>
#include <iostream>
#include "stb_image.h"

Texture::Texture(const char *file_path)
{
    int width, height, nr_channels;
    unsigned char *data = stbi_load(file_path, &width, &height, &nr_channels, 0);
    if (data)
    {
        glGenTextures(1, &m_ID);
        glBindTexture(GL_TEXTURE_2D, m_ID);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        // unbind
        glBindTexture(GL_TEXTURE_2D, 0);
        stbi_image_free(data);
    }
    else
    {
        std::cerr << "Failed to open texture" << std::endl;
    }
}

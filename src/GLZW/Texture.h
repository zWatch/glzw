//
// Created by z16cn on 2019/4/30.
//

#ifndef SAINT_TEXTURE_H
#define SAINT_TEXTURE_H

#include <string>
#include <glad.h>
#include <glfw3.h>
#include <stb_image.h>
#include <iostream>
struct Texture_s {
    unsigned int id;
    std::string type;
    std::string path;
};

typedef GLuint Texture_id;

inline Texture_id loadFromMem(GLbyte* data, int width, int height, int chan){
    Texture_id ret;
    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture); // all upcoming GL_TEXTURE_2D operations now have effect on this texture object
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    ret=texture;
    return ret;
};

inline Texture_id loadFromFile(const std::string& fp){
    // load and create a texture
    // -------------------------
    Texture_id ret;
    // load image, create texture and generate mipmaps
    int width, height, nrChannels;
    // The FileSystem::getPath(...) is part of the GitHub repository so we can find files on any IDE/platform; replace it with your own image path.
    auto data = stbi_load(fp.c_str(), &width, &height, &nrChannels, 0);
    if (data)
    {
        ret=loadFromMem((GLbyte*)data, width, height, nrChannels);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);
    return ret;
};

class Texture{
    Texture_id getTexture(bool NeedBlock){
        return 0;
    };
};

#endif //SAINT_TEXTURE_H
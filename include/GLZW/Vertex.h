//
// Created by z16cn on 2019/4/29.
//

#ifndef SAINT_VERTEX_H
#define SAINT_VERTEX_H

#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <vector>

struct Vertex {
    // position
    glm::vec3 Position;
    // normal
    glm::vec3 Normal;
    // texCoords
    glm::vec2 TexCoords;
    // tangent
    glm::vec3 Tangent;
    // bitangent
    glm::vec3 Bitangent;
};



#endif //SAINT_VERTEX_H
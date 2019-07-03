//
// Created by z16cn on 2019/4/29.
//
#pragma once

#include <vector>
//#include <json.hpp>
#include <fstream>
#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <vector>
#include <GLZW/glzw.hpp>

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

typedef GLuint VerticesID;

struct Vertices{

    std::vector<unsigned int> indices;
    std::vector<float> data;
    std::vector<int> size;
    std::vector<unsigned int> shader_pos;

    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;

    bool UseIndecies=true;
    bool useVOS=true;
public:
    Vertices(const std::string& file){

    }

    Vertices(const std::vector<float>& data
            , const std::vector<int>& size
            , const std::vector<unsigned int>& indices={}
            , const std::vector<unsigned int>& Gpos={}
    ){
        setData(data, size, indices, Gpos);
    }

    void setData(const std::vector<float>& data
            , const std::vector<int>& size
            , const std::vector<unsigned int>& indices={}
            , const std::vector<unsigned int>& Gpos={});

    void save(const std::string& file);

    void SendTOGpu();
    void use();

    ~Vertices(){
        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);
        glDeleteBuffers(1, &EBO);
    };
};

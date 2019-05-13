//
// Created by z16cn on 2019/4/29.
//
#pragma once

#include <vector>
#include <glad.h>
#include <glfw3.h>
#include <json.hpp>
#include <fstream>
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

typedef GLuint VerticesID;

struct Vertices{
    std::vector<unsigned int> indices;
    std::vector<float> data;
    std::vector<int> size;
    std::vector<int> Gpos;

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
            , const std::vector<int>& indeces={}
            , const std::vector<int>& Gpos={}
    ){
        this->data=data;
        this->size=size;

        if(indeces.empty()){
            UseIndecies= false;
        }
        if(Gpos.empty()){
            for(auto i=0; i<size.size(); i++){
                this->Gpos.push_back(i);
            }
        }

    }

    void save(const std::string& file){
        nlohmann::json json1{
                {"data", data},
                {"size", size},
        };

        std::ofstream ofstream1(file);
        ofstream1<<json1;
        ofstream1.close();
    };

    void SendTOGpu(){
        // create buffers/arrays
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        if(UseIndecies) {
            glGenBuffers(1, &EBO);
        }

        glBindVertexArray(VAO);
        // load data into vertex buffers
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        // A great thing about structs is that their memory layout is sequential for all its items.
        // The effect is that we can simply pass a pointer to the struct and it translates perfectly to a glm::vec3/2 array which
        // again translates to 3/2 floats which translates to a byte array.
        glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), &data[0], GL_STATIC_DRAW);

        if(UseIndecies){
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);
        }
        // set the vertex attribute pointers
        // vertex Positions
        auto sum=0;
        for(auto i: size){
            sum+=i;
        }
        size_t offset=0;
        auto interval=sum * sizeof(float);
        for(auto i=0; i<Gpos.size(); i++){
            GLuint pos=static_cast<GLuint>(Gpos[i]);
            glEnableVertexAttribArray(pos);
            glVertexAttribPointer(pos, size[i], GL_FLOAT, GL_FALSE, interval, (void*)offset);
            offset += size[i]* sizeof(float);
        }
        glBindVertexArray(0);
    }

    void use(){
        glBindVertexArray(VAO);
        if(UseIndecies){
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        }
    }
};

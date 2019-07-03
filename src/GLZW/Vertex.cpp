//
// Created by z16cn on 2019/5/14.
//

#include <GLZW/Vertex.hpp>
#include "Vertex.hpp"
#include <json.hpp>

void Vertices::SendTOGpu() {
    // create buffers/arrays
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    if(UseIndecies) {
        glGenBuffers(1, &EBO);
    }

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(data[0]), &(data[0]), GL_STATIC_DRAW);

    if(UseIndecies){
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(indices[0]), &(indices[0]), GL_STATIC_DRAW);
    }
    // set the vertex attribute pointers
    // vertex Positions
    auto sum=0;
    for(auto i: size){
        sum += i;
    }
    size_t offset=0;
    auto interval = sum * sizeof(float);
    for(auto i=0; i<size.size(); i++){
        auto pos = static_cast<GLuint>(shader_pos[i]);
        glVertexAttribPointer(pos, size[i], GL_FLOAT, GL_FALSE, interval, (void*)offset);
        glEnableVertexAttribArray(pos);
        offset += size[i] * sizeof(float);
    }
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    // remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Vertices::use() {
    glBindVertexArray(VAO);
}

void Vertices::setData(const std::vector<float> &data
        , const std::vector<int> &size
        , const vector<unsigned int> &indices
        ,const vector<unsigned int> &Gpos) {
    this->data=data;
    this->size=size;
    this->indices=indices;
    this->shader_pos=Gpos;
    UseIndecies = !indices.empty();

    if(Gpos.empty()){
        for(auto i=0; i<size.size(); i++){
            this->shader_pos.push_back(i);
        }
    }
}

void Vertices::save(const std::string &file) {
    nlohmann::json json1{
            {"data", data},
            {"size", size},
            {"indices", indices},
            {"UseIndecies", UseIndecies},
    };

    std::ofstream ofstream1(file);
    ofstream1<<json1;
    ofstream1.close();
}

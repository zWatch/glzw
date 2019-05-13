//
// Created by z16cn on 2019/4/29.
//

#ifndef SAINT_VERTEXBUILDER_H
#define SAINT_VERTEXBUILDER_H

#include "Vertex.hpp"
///布局、数据、

class VertexBuilder{
public:
    enum VertexType{
        position
        //          glm::vec3 Position;
        normal
        //        glm::vec3 Normal;
        texCoords
        //        glm::vec2 TexCoords;
        tangent
        //        glm::vec3 Tangent;
        bitangent
        //       glm::vec3 Bitangent;
    };


    int pos=0;
    std::vector<VertexType> v;
    std::vector<int>& sizeL;
    anyVertex anyVertex1;

    VertexBuilder(const std::vector<VertexType>& v, const std::vector<int>& sizeL){

    };
    ~VertexBuilder(){};

    VertexBuilder& begin(){
        return *this;
    };
    VertexBuilder& next(){

        return *this;
    };
    VertexBuilder& end(){
        return *this;
    };

    bool Build(){


    }
};
#endif //SAINT_VERTEXBUILDER_H

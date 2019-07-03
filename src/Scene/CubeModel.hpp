//
// Created by z16cn on 2019/5/11.
//

#pragma once

#include "AbstractMesh.hpp"
#include <Common/zwhead.hpp>
#include <GLZW/Vertex.hpp>
#include <GLZW/Shader.hpp>

class CubeMesh{
    Shader cubeShader;
    Vertices vertices;
public:
    CubeMesh();
    void init();
    void draw();
};

class CubeModel{
    CubeMesh cubeMesh;
public:
    CubeModel();

    void init(){
        OnceInit(void());
        cubeMesh.init();
    }

    void draw(){
        cubeMesh.draw();
    }
};
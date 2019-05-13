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
    Vertices vertices{
            {
                -0.9f,-0.9f,-0.1f,   0,0,1,             //0
                -0.9f,0.9f,-0.9f,   0,1,0,             //4
                0.9f,0.9f,-0.1f,     1,1,1,             //2
                0.9f,-0.9f,-0.1f,    1,0,1,             //1
                0.9f,-0.9f,-0.9f,   1,0,0,             //6
                0.9f,0.9f,-0.9f,    0.9f,0.9f,0,             //5
                -0.9f,0.9f,-0.1f,    0,1,1,             //3
                -0.9f,-0.9f,-0.9f,  0,0,0             //7
            },{
                3,3
            },{
                0, 1, 2,
                0, 2, 3,
                2, 5, 4,
                2, 4, 3,
                1, 6, 5,
                1, 5, 2,

                0,4,7,
                0,3,4,
                0,7,1,
                0,6,1,
                4,5,6,
                4,6,7
            }
    };
public:
    void init();
    void draw();
};

class CubeModel{
    CubeMesh cubeMesh;
public:
    void init(){
        OnceInit(void());
        cubeMesh.init();
    }
    void draw(){
        cubeMesh.draw();
    }
};
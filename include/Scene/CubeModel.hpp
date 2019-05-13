//
// Created by z16cn on 2019/5/11.
//

#pragma once

#include "AbstractMesh.hpp"
#include <Common/zwhead.hpp>
#include <GLZW/Vertex.hpp>
class CubeMesh : public AbstractMesh{
    Shader cubeShader;
    Vertices vertices{
            {
                -1,-1,1,   0,0,1,             //0
                -1,1,-1,   0,1,0,             //4
                1,1,1,     1,1,1,             //2
                1,-1,1,    1,0,1,             //1
                1,-1,-1,   1,0,0,             //6
                1,1,-1,    1,1,0,             //5
                -1,1,1,    0,1,1,             //3
                -1,-1,-1,  0,0,0             //7
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
    void init() override {
        OnceInit(void());
        vertices.SendTOGpu();
    };
    void draw() override {
        // draw our first triangle
        //glUseProgram(shader);
        cubeShader.use();
        //glBindVertexArray(vao); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        vertices.use();
        glDrawElements(GL_TRIANGLES, 3*2*6, GL_UNSIGNED_INT, 0);
        //glBindVertexArray(0); // no need to unbind it every time
    };
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
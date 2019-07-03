//
// Created by z16cn on 2019/5/14.
//

#include <Scene/CubeModel.hpp>
static float vpos[]={
        -1.0f,-1.0f,-0.1f,   0,0,1,             //0
        -1.0f,1.0f,-1.0f,   0,1,0,             //4
        1.0f,1.0f,-0.0f,     1,1,1,             //2
        1.0f,-1.0f,-0.0f,    1,0,1,             //1
        1.0f,-1.0f,-1.0f,   1,0,0,             //6
        1.0f,1.0f,-1.0f,    1.0f,1.0f,0,             //5
        -1.0f,1.0f,-0.0f,    0,1,1,             //3
        -1.0f,-1.0f,-1.0f,  0,0,0             //7
};

static int indices[]={
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
};

CubeMesh::CubeMesh():vertices({vpos, vpos+ sizeof(vpos)/ sizeof(vpos[0])}
,{3,3},{indices, indices+sizeof(indices)/ sizeof(indices[0])}){

}

void CubeMesh::init()  {
    OnceInit(void());
    cubeShader=Shader::createFromFile("resource/ColorTri.vs","resource/ColorTri.fs");
    vertices.SendTOGpu();
};

void CubeMesh::draw()  {
    cubeShader.use();
    //cubeShader.set("hello", 2);
    //printf(glzw::getGLErrorInfo());
    vertices.use();
    glDrawElements(GL_TRIANGLES, vertices.indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
};

CubeModel::CubeModel():cubeMesh(){

}

//
// Created by z16cn on 2019/5/14.
//

#include <Scene/CubeModel.hpp>
void CubeMesh::init()  {
    OnceInit(void());
    cubeShader=Shader::createFromFile("resource/ColorTri.vs","resource/ColorTri.fs");
    vertices.SendTOGpu();
};
void CubeMesh::draw()  {
    // draw our first triangle
    //glUseProgram(shader);
    cubeShader.use();
    //glBindVertexArray(vao); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
    vertices.use();
    glDrawElements(GL_TRIANGLES, 3*2*6, GL_UNSIGNED_INT, 0);
    //glBindVertexArray(0); // no need to unbind it every time
};
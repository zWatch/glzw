//
// Created by z16cn on 2019/5/19.
//

#ifndef GLZW_TESTMODEL_H
#define GLZW_TESTMODEL_H

#include <GLZW/glzw.hpp>
#include "AbstractMesh.hpp"
#include <GLZW/Vertex.hpp>
#include <GLZW/Shader.hpp>
#include <Common/zwhead.hpp>
class testAbsMesh : public AbstractMesh{
public:
    unsigned int shader=0;
    unsigned int vao=0;

    Vertices* vertices;
    Shader* shader_;

    void init()override;
    void draw() override;
    void CreateShader(){
        //Shader shader1("resource/Triangle.vs","resource/Triangle.fs");
        shader_=new Shader("resource/ColorTri.vs","resource/ColorTri.fs");
        shader = shader_->ID;
    };

    void CreateVertices(){
        vertices=new Vertices{
                {   //V3 C3
                        -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
                        0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
                        0.0f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f
                },
                {3, 3},
                {0, 1, 2}
                //{2, 1, 0}
        };
        vertices->SendTOGpu();
        vao=vertices->VAO;

        /*
        float vertices2[] = {
                0.5f,  0.5f, 0.0f,0.5f,  0.5f, 0.0f,  // top right
                0.5f, -0.5f, 0.0f,0.0f, 0.5f, 0.0f,  // bottom right
                -0.5f, -0.5f, 0.0f,-0.0f, 0.5f, 0.0f,  // bottom left
                -0.5f,  0.5f, 0.0f,-0.5f,  0.0f, 0.0f,   // top left
        };
        unsigned int indices[] = {  // note that we start from 0!
                0, 1, 3,  // first Triangle
                1, 2, 3   // second Triangle
        };

        unsigned int VBO, VAO, EBO;
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);
        // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 2*3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 2*3 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);

        // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        // remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
        //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

        // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
        // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
        glBindVertexArray(0);
        vao=VAO;
        //*/
    }

    void Draw(){

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shader);
        //shader_->use();

        //glBindVertexArray(vao); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        vertices->use();

        //GLuint indices[]={0,1,2};
        //glDrawArrays(GL_TRIANGLES, 0, 3);
        glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
        //gladLoadGL();
        //glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, indices);
    }
};

class testModel {



};

#endif //GLZW_TESTMODEL_H

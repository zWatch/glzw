//
// Created by z16cn on 2019/7/1.
//

#include <glad.h>
#include <glfw3.h>

#include <iostream>
#include <Window/zwWindow.hpp>
#include <time.h>
#include <glm/gtc/matrix_transform.hpp>
extern void framebuffer_size_callback(GLFWwindow* window, int width, int height);
extern void processInput(GLFWwindow *window);

// settings
/*
float vertices[] = {
    1.0f,  1.0f, 1.0f, 0.0f,  0.0f, 1.0f,  // top right for
    1.0f, -1.0f, 1.0f, 0.0f, 1.0f, 0.0f,  // bottom right
    -1.0f, -1.0f, 1.0f, 0.0f, 1.0f, 1.0f,  // bottom left
    -1.0f,  1.0f, 1.0f, 1.0f,  0.0f, 0.0f,   // top left

    -1.0f,  1.0f, -1.0f, 1.0f,  0.0f, 1.0f,   // top left back
    -1.0f, -1.0f, -1.0f, 1.0f, 1.0f, 0.0f,  // bottom left
    1.0f, -1.0f, -1.0f, 1.0f, 1.0f, 1.0f,  // bottom right
    1.0f,  1.0f, -1.0f, 0.0f,  0.0f, 0.0f,  // top right
};
//*/
float vertices[] = {
        1.0f,  1.0f, 1.0f, 0.0f,  0.0f, 1.0f,  // top right for
        1.0f, -1.0f, 1.0f, 0.0f, 1.0f, 0.0f,  // bottom right
        -1.0f, -1.0f, 1.0f, 0.0f, 1.0f, 1.0f,  // bottom left
        -1.0f,  1.0f, 1.0f, 1.0f,  0.0f, 0.0f,   // top left

        -1.0f,  1.0f, -1.0f, 1.0f,  0.0f, 1.0f,   // top left back
        -1.0f, -1.0f, -1.0f, 1.0f, 1.0f, 0.0f,  // bottom left
        1.0f, -1.0f, -1.0f, 1.0f, 1.0f, 1.0f,  // bottom right
        1.0f,  1.0f, -1.0f, 0.0f,  0.0f, 0.0f,  // top right
};
unsigned int indices[] = {  // note that we start from 0!
    0,3,2,
    0,2,1,
    5,4,7,
    6,5,7,
    0,1,7,
    1,6,7,
    2,3,4,
    2,4,5,
    0,7,3,
    3,7,4,
    1,2,5,
    1,5,6,
};

class CubeModel2: public AbstractMesh{
    Vertices* vertices2;
    Shader* shader;

    glm::mat4 rotate=glm::mat4(1.0f);//=glm::rotate() ;

    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
public:
    void init() override {
        vertices2=new Vertices(
                {vertices, vertices+ sizeof(vertices)/ sizeof(vertices[0])}
                ,{3, 3}
                ,{indices, indices+sizeof(indices)/sizeof(indices[0])});
        vertices2->SendTOGpu();
        //=Shader::createFromFile();
        shader=new Shader("../resource/RotateColorTri.vs","../resource/RotateColorTri.fs");
        rotate=glm::scale(rotate, glm::vec3(0.5f, 0.5f, 0.5f));
        glEnable(GL_CULL_FACE);
        glFrontFace(GL_CCW);
    }

    void draw() override {

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        shader->use();

        rotate=glm::rotate(rotate, (float)0.02, glm::normalize(glm::vec3(0, 1, 0)));
        rotate=glm::rotate(rotate, (float)0.0013, glm::normalize(glm::vec3(1, 0, 0)));

        shader->set("rotateMatrix", rotate);
        vertices2->use();
        glDrawElements(GL_TRIANGLES, 6*6, GL_UNSIGNED_INT, 0);
    }
};


class zwWindow2: public zwWindow{
    CubeModel2* cubeModel2;

public:
    void init() override {
        zwWindow::init();
        OnceInit(void())
        cubeModel2=new CubeModel2();
        cubeModel2->init();
    }

    void tick() override {
        //zwWindow::tick();
        /*
        static int counter=0;
        static clock_t start=0;
        static clock_t end=0;
        counter++;
        if(counter>=60){
            counter=0;
            end=clock();
            printf("%ld\n", end/CLOCKS_PER_SEC);
            //printf("%lf\n", counter/(double)((end-start)/CLOCKS_PER_SEC));
            start=end;
        }
         //*/
        cubeModel2->draw();
    }
};

int main()
{
    //long x=12'2312'12;
    zwWindow2 zwWindow1;
    zwWindow1.init();
    zwWindow1.run();
    return 0;
}

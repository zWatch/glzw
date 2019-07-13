//
// Created by z16cn on 2019/7/1.
//

#include <glad.h>
#include <glfw3.h>

#include <iostream>
#include <Window/zwWindow.hpp>
#include <time.h>
extern void framebuffer_size_callback(GLFWwindow* window, int width, int height);
extern void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
float vertices[] = {
0.5f,  0.5f, 0.0f,  // top right
0.5f, -0.5f, 0.0f,  // bottom right
-0.5f, -0.5f, 0.0f,  // bottom left
-0.5f,  0.5f, 0.0f   // top left
};
unsigned int indices[] = {  // note that we start from 0!
0, 1, 3,  // first Triangle
1, 2, 3   // second Triangle
};

class CubeModel2: public AbstractMesh{
    Vertices* vertices2;
    Shader* shader;
    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
public:
    void init() override {
        vertices2=new Vertices(
                {vertices, vertices+ sizeof(vertices)/ sizeof(vertices[0])}
                ,{3,}
                ,{indices, indices+sizeof(indices)/sizeof(indices[0])});
        vertices2->SendTOGpu();
        //=Shader::createFromFile();
        shader=new Shader("../resource/NoColorTri.vs","../resource/NoColorTri.fs");
    }

    void draw() override {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        shader->use();
        vertices2->use();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
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
    zwWindow2 zwWindow1;
    zwWindow1.init();
    zwWindow1.run();
    return 0;
}

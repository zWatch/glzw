//
// Created by z16cn on 2019/5/2.
//

#pragma once

#include <glad.h>
#include <glfw3.h>
#include <iostream>
#include <Scene/MyMesh.hpp>
#include <Scene/AbstractMesh.hpp>
#include <GLZW/Vertex.hpp>
#include <stb_image.h>
#include <stb_image_write.h>
#include <GLZW/glzw.hpp>
#include <Common/zwhead.hpp>
#include <Scene/Scene.hpp>
#include <Scene/CubeModel.hpp>
#include <GLZW/Shader.hpp>
using namespace std;


// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window);

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void mouse_callback(GLFWwindow* window, double xpos, double ypos);

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

class testAbsMesh :public AbstractMesh{
public:
    unsigned int shader=0;
    unsigned int vao=0;

    void init() override;

    void draw() override;


    void CreateShader(){
        //Shader shader1("resource/Triangle.vs","resource/Triangle.fs");
        Shader shader1("resource/ColorTri.vs","resource/ColorTri.fs");
        shader= shader1.ID;
    };

    void CreateVertices(){
        /*
        Vertices vertices1{
            {-0.5f, -0.5f, 0.0f, // left
             0.25f, -0.5f, 0.0f, // right
             0.0f,  0.5f, 0.0f  // top
           },
           {3}
        };
        */
        Vertices vertices1{
                {   //V3 C3
                        -0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
                        0.25f, -0.5f, -0.1f, 0.0f, 1.0f, 0.0f,
                        0.0f,  0.5f, -0.2f, 0.0f, 0.0f, 1.0f
                },
                {3,3}
        };

        vertices1.SendTOGpu();
        vao=vertices1.VAO;
    }

    void Draw(){
        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // draw our first triangle
        glUseProgram(shader);
        glBindVertexArray(vao); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        glDrawArrays(GL_TRIANGLES, 0, 3);
        //glBindVertexArray(0); // no need to unbind it every time
     }
};

class GLFWinit{
public:

    static void init(){
        OnceInit(void());
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
#endif
        glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
    }
};

class zwWindow{
    GLFWwindow* window=nullptr;
    testAbsMesh testAbsMesh1;
    CubeModel cubeModel;
public:
    void init() {
        OnceInit(void());
        GLFWinit::init();
        window = glfwCreateWindow(400, 300,"hello", nullptr, nullptr);
        glfwMakeContextCurrent(window);
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cout << "Failed to initialize GLAD" << std::endl;
        }
        glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
        glViewport(0,0,400,300);

        testAbsMesh1.init();
        cubeModel.init();
    };
    void run(){
        glClearColor(0.5f, 1.0f, 1.0f, 1.0f);
        glfwShowWindow(window);
        glfwSwapInterval(1);
        static bool hasSave=false;
        while(!glfwWindowShouldClose(window)){
            testAbsMesh1.draw();
            cubeModel.draw();
            glfwSwapBuffers(window);
            if(!hasSave){
                glzw::save();
                hasSave=true;
            }
            glfwPollEvents();
        }

        glfwDestroyWindow(window);
        glfwTerminate();
    };
};

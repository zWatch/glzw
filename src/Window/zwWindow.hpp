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
#include <Scene/testModel.h>
#include <GLZW/glzw.hpp>

#include "AbstractWindow.hpp"
using namespace std;

//region callback

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
void processInput(GLFWwindow *window);

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

// glfw: whenever the mouse moves, this callback is called
void mouse_callback(GLFWwindow* window, double xpos, double ypos);

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

//endregion callback

class GLFWinit{
public:
    static void init();
};

class zwWindow : public AbstractWindow{
    GLFWwindow* window=nullptr;
    //testAbsMesh testAbsMesh1;
    //CubeModel cubeModel;
    constexpr static int DEFAULT_WIDTH=800;
    constexpr static int DEFAULT_HEIGHT=600;
public:
    void init() override;
    void run() override;
    void tick() override;
};

//
// Created by z16cn on 2019/4/29.
//
#include <glad.h>
#include <glfw3.h>
#include <future>
#include <thread>
#include <stdio.h>
#include <iostream>
using namespace std;

volatile bool running = true;
volatile int * volatile a;
static void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

static void key_callback2(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    static volatile int i=0;
    cout<<"thread "<<std::this_thread::get_id();
    printf(" window %p recv %d key %d\n", window, i++,key);
}

void threadOne(GLFWwindow* window){
    cout<<"thread "<<std::this_thread::get_id();
    printf(" get window %p\n", window);
    glfwMakeContextCurrent(window);

    glClearColor(0.5,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);

    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);
    glfwSwapInterval(1);
    while(!glfwWindowShouldClose(window)){
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
    }
    glfwMakeContextCurrent(NULL);
    return ;
}

int main(){

    glfwSetErrorCallback(error_callback);

    if (!glfwInit())
        exit(EXIT_FAILURE);

    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
    auto window1=glfwCreateWindow(800, 600, "Hello1", nullptr, nullptr);
    auto window2=glfwCreateWindow(800, 600, "Hello2", nullptr, nullptr);
    //glfwShowWindow(window1);
    glfwSetKeyCallback(window1, key_callback2);
    glfwSetKeyCallback(window2, key_callback2);

    glfwShowWindow(window1);
    glfwShowWindow(window2);

    glfwMakeContextCurrent(window2);
    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
    glfwMakeContextCurrent(nullptr);

    //glfwSetWindowTitle();

    //glfwGetCurrentContext();

    std::thread a1(threadOne, window1);
    std::thread a2(threadOne, window2);

    while(running){
        glfwWaitEvents();
        char allQuit=TRUE;
        char iClose=glfwWindowShouldClose(window1);
        if(iClose){
            glfwHideWindow(window1);
        }
        allQuit &= iClose;

        iClose=glfwWindowShouldClose(window2);
        if(iClose){
            glfwHideWindow(window2);
        }
        allQuit &= iClose;
        if(allQuit){
            running = GLFW_FALSE;
        }
    }
    glfwPostEmptyEvent();
    if(a1.joinable())
        a1.join();
    if(a2.joinable())
        a2.join();
    glfwDestroyWindow(window1);
    glfwDestroyWindow(window2);
    glfwTerminate();
    return 0;
}

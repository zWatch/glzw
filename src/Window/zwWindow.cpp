//
// Created by z16cn on 2019/5/3.
//

#include <Window/zwWindow.hpp>



//region callback impl

void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
//
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{

}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{

}

//endregion

void GLFWinit::init() {
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

void zwWindow::init(){
    OnceInit(void());
    GLFWinit::init();
    window = glfwCreateWindow(DEFAULT_WIDTH, DEFAULT_HEIGHT,"hello", nullptr, nullptr);
    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
    }
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glViewport(0, 0, DEFAULT_WIDTH, DEFAULT_HEIGHT);
    //testAbsMesh1.init();
    //cubeModel.init();
}

void zwWindow::run(){
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glfwShowWindow(window);
    glfwSwapInterval(1);
    static bool hasSave=false;

    while(!glfwWindowShouldClose(window)){
        glClear(GL_COLOR_BUFFER_BIT);
        //testAbsMesh1.draw();
        //    cubeModel.draw();
        tick();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
}

void zwWindow::tick(){

}

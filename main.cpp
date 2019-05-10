#include <glad.h>
#include <glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
// #include <Scene/Model.hpp>
#include <Scene/Camera.hpp>
#include <Scene/Shader.hpp>
#include <iostream>

#include <Window/zwWindow.hpp>

#define  STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image_write.h>
#include <admex.h>

int main()
{
    zwWindow * window;
    window = new zwWindow();
    window->init();
    window->run();
    return 0;
};
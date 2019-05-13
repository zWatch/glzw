#include <glad.h>
#include <glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <Scene/Camera.hpp>
#include <iostream>

#include <Window/zwWindow.hpp>

#include <admex.h>

int main()
{
    zwWindow * window;
    window = new zwWindow();
    window->init();
    window->run();
    return 0;
};
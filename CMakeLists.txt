cmake_minimum_required(VERSION 3.12)
project(Saint)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
include_directories(3rd/include)
link_directories(3rd/libs)

add_subdirectory(test)

set(GLAD_C ${CMAKE_CURRENT_SOURCE_DIR}/3rd/src/glad.c)

add_executable(Saint main.cpp
        ${GLAD_C}
        src/Platform/Windows/OpenGL/zwWindow.cpp
        )
#target_link_libraries(Saint glfw3 opengl32 assimp)
target_link_libraries(Saint glfw3 opengl32)



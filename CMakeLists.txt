cmake_minimum_required(VERSION 3.11.1)
project(glzw)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)
#set(CMAKE_C_STANDARD 17)

include_directories(src)
include_directories(3rd/include)
link_directories(3rd/libs)

add_subdirectory(test)

set(GLAD_C ${CMAKE_CURRENT_SOURCE_DIR}/3rd/src/glad.c)
aux_source_directory(src/GLZW/ GLZW_SOURCE)
aux_source_directory(src/Scene/ GLZW_SCENE_SOURCE)
aux_source_directory(src/Window/ GLZW_WINDOW_SOURCE)

add_executable(glzw main.cpp
        ${GLAD_C}
        ${GLZW_SOURCE}
        ${GLZW_SCENE_SOURCE}
        ${GLZW_WINDOW_SOURCE}
        )

add_executable(Triangle src/learn/Triangle.cpp
        ${GLAD_C}
        )

target_link_libraries(Triangle glfw3 opengl32)
add_executable(MyTriangle src/learn/MyTriangle.cpp
        ${GLAD_C}
        ${GLZW_SOURCE}
        ${GLZW_SCENE_SOURCE}
        ${GLZW_WINDOW_SOURCE}
        )

target_link_libraries(MyTriangle glfw3 opengl32)



add_executable(MyCube2 src/learn/MyCube2.cpp
        ${GLAD_C}
        ${GLZW_SOURCE}
        ${GLZW_SCENE_SOURCE}
        ${GLZW_WINDOW_SOURCE}
        )

target_link_libraries(MyCube2 glfw3 opengl32)

#target_link_libraries(Saint glfw3 opengl32 assimp)
target_link_libraries(glzw glfw3 opengl32)

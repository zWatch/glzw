cmake_minimum_required(VERSION 3.12)
project(glzw)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
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
#target_link_libraries(Saint glfw3 opengl32 assimp)
target_link_libraries(Saint glfw3 opengl32)

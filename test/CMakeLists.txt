add_executable(testGLFWthreadSafe testGLFWthreadSafe.cpp ../3rd/src/glad.c)
target_link_libraries(testGLFWthreadSafe opengl32 glfw3)

add_executable(AutoRightClick ClassFWin/AutoRightClick.cpp)
#add_executable(P3.5.5 ClassFCoun/P3.3.5.cpp)
add_executable(Test_Sizeof ClassFCoun/sizeof.cpp)
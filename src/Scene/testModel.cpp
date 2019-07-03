//
// Created by z16cn on 2019/5/19.
//

#include "Scene/testModel.h"
void testAbsMesh::init() {
    OnceInit(void());
    CreateShader();
    CreateVertices();
}

void testAbsMesh::draw() {
    Draw();
}


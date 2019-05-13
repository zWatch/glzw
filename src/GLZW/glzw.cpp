//
// Created by z16cn on 2019/5/13.
//
#include <GLZW/glzw.hpp>

namespace  glzw{

    void save(){
        std::string filename="hello.png";
        unsigned long lImageSize;
        GLbyte * pBits= nullptr;
        GLint iViewport[4];
        GLenum lastBuffer;
        glGetIntegerv(GL_VIEWPORT, iViewport);
        lImageSize = iViewport[2]*3*iViewport[3];
        pBits= new GLbyte[lImageSize];
        if(pBits == nullptr){
            cout<<"bad malloc"<<endl;
            return ;
        }
        glPixelStorei(GL_PACK_ALIGNMENT, 1);
        glPixelStorei(GL_PACK_ROW_LENGTH, 0);
        glPixelStorei(GL_PACK_SKIP_ROWS, 0);
        glPixelStorei(GL_PACK_SKIP_PIXELS, 0);

        glGetIntegerv(GL_READ_BUFFER, (int*)&lastBuffer);
        glReadBuffer(GL_FRONT);
        //glReadPixels(0,0,iViewport[2], iViewport[3], GL_BGR, GL_UNSIGNED_BYTE, pBits);
        glReadPixels(0, 0, iViewport[2], iViewport[3], GL_RGB, GL_UNSIGNED_BYTE, pBits);
        glReadBuffer(lastBuffer);

        //stbi_set_flip_vertically_on_load(1);
        stbi_flip_vertically_on_write(1);
        stbi_write_png(filename.c_str(), iViewport[2], iViewport[3],3, pBits, 0);
    }
}

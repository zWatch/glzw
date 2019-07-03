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
    const char* getGLErrorInfo()
    {
        //GL_NO_ERROR ：（0）当前无错误值
        //GL_INVALID_ENUM ：（1280）仅当使用非法枚举参数时，如果使用该参数有指定环境，则返回 GL_INVALID_OPERATION
        //GL_INVALID_VALUE ：（1281）仅当使用非法值参数时，如果使用该参数有指定环境，则返回 GL_INVALID_OPERATION
        //GL_INVALID_OPERATION ：（1282）命令的状态集合对于指定的参数非法。
        //GL_STACK_OVERFLOW ：（1283）压栈操作超出堆栈大小。
        //GL_STACK_UNDERFLOW ：（1284）出栈操作达到堆栈底部。
        //GL_OUT_OF_MEMORY ：（1285）不能分配足够内存时。
        //GL_INVALID_FRAMEBUFFER_OPERATION ：（1286）当操作未准备好的真缓存时。
        //GL_CONTEXT_LOST ：（1287）由于显卡重置导致 OpenGL context 丢失
        GLenum errorId=glGetError();
        const char* ret=nullptr;
        switch (errorId)
        {
            case GL_NO_ERROR:
                ret="GL No Error\n";
                break;
            case GL_INVALID_ENUM:
                ret="GL Invalid Enum\n";
                break;
            case GL_INVALID_VALUE:
                ret= ("GL Invalid Value\n");
                break;
            case GL_INVALID_OPERATION:
                ret= ("GL Invalid Operation\n");
                break;
            case GL_OUT_OF_MEMORY:
                ret= ("GL Out Of Memory\n");
                break;
            case GL_INVALID_FRAMEBUFFER_OPERATION:
                ret= ("GL Invalid FrameBuffer Operation\n");
                break;
            case  GL_STACK_OVERFLOW:
                ret= ("GL Stack Overflow\n");
                break;
            case GL_STACK_UNDERFLOW:
                ret= ("GL Stack Underflow\n");
                break;
                //case GL_TABLE_TOO_LARGE:
                //    ret= ("GL Table Too Large\n");
                //    break;
            default:
                ret= "GL Undefined Error";
                break;
        };
        return ret;
    }
}

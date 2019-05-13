//
// Created by z16cn on 2019/5/13.
//

#pragma oncce

#define OnceInit(ret) static bool hadInit=false; if(hadInit){    return ret;    }   hadInit=true;

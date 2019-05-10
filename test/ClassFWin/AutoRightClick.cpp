//
// Created by z16cn on 2019/5/3.
//
#include <iostream>
#include <windows.h>
#include <thread>
using namespace std;

int main(){
    auto hWnd= FindWindow(nullptr, "Minecraft 1.12.2");
    int wait;
    if(IsWindow(hWnd)){
        cout<<"Wait start"<<endl;
        cin>>wait;
        while(true){
            PostMessage(hWnd, WM_RBUTTONDOWN, VK_LBUTTON, 1);
            //std::this_thread::sleep_for(chrono::milliseconds(100));
            PostMessage(hWnd, WM_RBUTTONUP, VK_LBUTTON, 1);
            std::this_thread::sleep_for(chrono::milliseconds(50));
        }
    }else{
        cout<<"No Found this window"<<endl;
    }
    return 0;
}
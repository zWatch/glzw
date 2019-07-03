//
// Created by z16cn on 2019/7/2.
//

#ifndef GLZW_ABSTRACTWINDOW_HPP
#define GLZW_ABSTRACTWINDOW_HPP


class AbstractWindow {
public:
    virtual void init()=0;
    virtual void run()=0;
    virtual void tick()=0;
};


#endif //GLZW_ABSTRACTWINDOW_HPP

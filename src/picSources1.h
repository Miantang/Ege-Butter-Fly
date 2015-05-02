/***************************************************************************
Copyright (c) 2015- MianTang 

https://github.com/Miantang/Ege-Butter-Fly

Taking part in the mooc class in NetEase of C++ introduction <http://mooc.study.163.com/course/BUPT-1000003015#/info>
Related to a competition about creating  EGE Draws or Animations .

Image code was edited by Adobe Illustrator from source paintings *.jpg(fetched from Baidu Tieba) to SVG Vector ,
then convert them to the Cpp code for this software via a software made myself.(Based on Flash Actionscript)
<https://github.com/Miantang/AsToEge>

This software is released under the MIT License 
<http://www.opensource.org/licenses/mit-license.php>
****************************************************************************/
#pragma once
#include <graphics.h>
#include "animaControll.h"

class RectUp: public Image {
    public :
        RectUp();
};
class RectBottom : public Image {
    public :
        RectBottom();
};
class RectFilled: public Image {
    public :
        RectFilled(color_t, int, int);
};
class P1 : public Image {
    public :
        P1();
        void draw();
};

class P2 : public Image {
    public :
        P2();
        void draw();
};
class P3 : public Image {
    public :
        P3();
        void draw();
};
class P4 : public Image {
    public :
        P4();
        void draw();
};
class P5 : public Image {
    public :
        P5();
        void draw();
};
class P6 : public Image {
    public :
        P6();
        void draw();
};
class P7 : public Image {
    public :
        P7();
        void draw();
};
class P8 : public Image {
    public :
        P8();
        void draw();
};
class P9 : public Image {
    public :
        P9();
        void draw();
};
class P10 : public Image {
    public :
        P10();
        void draw();
};
class P11 : public Image {
    public :
        P11();
        void draw();
};

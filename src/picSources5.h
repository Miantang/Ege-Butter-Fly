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

class Plast : public Image {
    public :
        Plast();
        void draw();
};
class Pall : public Image {
    public :
        Pall();
        void draw();
};

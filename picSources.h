#pragma once
#include <graphics.h>
#include "animaControll.h"

void lineStyle(float, color_t, PIMAGE);

class TaijiImg : public Image {
    public :
        PIMAGE img;
        TaijiImg();
        void draw();
};
class YSimg : public Image {
    public :
        PIMAGE img;
        YSimg();
        void draw();
};

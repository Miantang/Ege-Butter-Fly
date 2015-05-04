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
#include "animaControll.h"

// Combine setcolor and setlinewidth to a single function , for easier converting of Flash code.
void lineStyle(float thickness, color_t color, PIMAGE img) {
    setcolor(color, img);setlinewidth(thickness, img);
}

/**
* @brief Init screen of EGE.
*/
Screen::Screen(int width = 640, int height = 480) {
    if ( width >= 2000 || height >= 2000 ||  width <= 0 || height <= 0) {
        char invalid[] = "invalid screen size";
        outtextxy(0, 0, invalid);
        exit(0);
    } else {
        this->width = width;
        this->height = height;
        initgraph(this->width, this->height);
    }
};

Screen::~Screen() {
    closegraph();
}

int Screen::getWidth() {
    return width;
} 

int Screen::getHeight () {
    return height;
}

/**
* @brief Base class for Picture and Text .
*/
Image::Image() {};
Image::~Image() {
    delimage(img);
};
    
void Image::render(){
    putimage_alphatransparent(NULL, img, (int)x, (int)y, 0xF1F1F1, (unsigned char)alpha);
}

void Image::animation() {
    switch(animaPreset) {
        case LEFT :
            x -= dx;
            break;
        case RIGHT :
            x += dx;
            break;
        case ALPHA :
            alpha += da;
        	if (alpha <= 0)	da = 1;
        	if (alpha >= 0xFF) da = -1;
        	break;
        case HOLD :
            break;
        case LEFTALPHA:
             x -= dx;
             alpha += da;
        	if (alpha <= 0)	da = 1;
        	if (alpha >= 0xFF) da = -1;
        	break; 
        case RIGHTALPHA:
             x += dx;
             alpha += da;
        	if (alpha <= 0)	da = 1;
        	if (alpha >= 0xFF) da = -1;
        	break; 
    	case ALPHAHOLD:
            alpha += da;
        	if (alpha >= 0xFF)  {
        	    da = 0;
        	    alpha = 0xFF;
        	}
        	if(alpha <= 0){
        	    da = 0;
        	    alpha = 0;
        	}
        	break; 
    }
}

/**
* @brief Text element to display on the screen , extend Image .
*/    
Text::Text(int _x, int _y, LPCTSTR outtxt, int preset) {
    isCleared = false;
    animaPreset = preset;
    textstring = outtxt;
    x = _x;// toCenterX(_x);
    y =  _y;//toCenterY(_y);
    img = newimage(1000, 1000);
    setbkcolor(0xF1F1F1,img);
    setcolor(0x880000, img);
    alpha = 255;dx = 0.1; da = 5;
    setfont(32, 0,"ºÚÌå", img);
    outtextxy(0, 0, textstring, img);
}

//convert the anchor to the cneter of text, for operating easier.
inline int Text::toCenterX(int x) {
    return  x-textwidth(textstring, img)/2;
}

inline int Text::toCenterY(int y) {
    return  y-textheight(textstring, img)/2;
}

/**
* @brief Attach timeline to the Image[or its child class] for displaying in its Composition
*/
Layer::Layer(){}
Layer::Layer(float inTime, float outTime, Image* image) {
    source = image;
    this->inTime = inTime;
    this->outTime = outTime; 
}

void Layer::init(float inTime, float outTime, Image* image) {
    source = image;
    this->inTime = inTime;
    this->outTime = outTime; 
}

/**
* @brief Display the Layer(s) contained ,foreach currentTime to present the elements in proper time on the screen.
*/
Composition::Composition(int n, Layer* layers) {
    numOfLayers = n;
    this->layers = layers;
}

void Composition::present(float currentTime) {
    for(int i = 0; i < numOfLayers; i++) {
        if(currentTime < layers[i].inTime){
            //wait and do nothing
        }else if(currentTime >= layers[i].inTime && currentTime <= layers[i].outTime) {
            layers[i].source->animation();
        }else{
            if(layers[i].source->isCleared) {
                layers[i].source->isCleared = true;
                delimage(layers[i].source->img);
            } 
        }
    }    
    
    cleardevice();
    
    for(int i = 0; i < numOfLayers; i++) {
        if(currentTime < layers[i].inTime){
            //wait and do nothing
        }else if(currentTime >= layers[i].inTime && currentTime <= layers[i].outTime) {
            layers[i].source->render();
        }else{
            if(layers[i].source->isCleared) {
                layers[i].source->isCleared = true;
                delimage(layers[i].source->img);
            }
        }
    }
                 
}

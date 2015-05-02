#include "animaControll.h"

void lineStyle(float thickness, color_t color, PIMAGE img) {
    setcolor(color, img);setlinewidth(thickness, img);
}

Screen::Screen(int width = 640, int height = 480) {
    if ( width >= 2000 || height >= 2000 ||  width <= 0 || height <= 0) {
        char invalid[] = "invalid screen size";
        outtextxy(0, 0, invalid);
        exit(0);
    }else{
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

Image::Image() { };
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
    }
}
       
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

Composition::Composition(int n, Layer* layers) {
    numOfLayers = n;
    this->layers = layers;
}

void Composition::present(float currentTime) {
    for(int i = 0; i < numOfLayers; i++) {
        if(currentTime < layers[i].inTime){
            //wait;
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
            //wait;
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

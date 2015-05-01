#include "animaControll.h"

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
    putimage_alphatransparent(NULL, img, (int)x, (int)y, 0xDAD0BD, (unsigned char)alpha);
}
void Image::clear(){
    putimage_alphatransparent(NULL, img, (int)x, (int)y, 0xDAD0BD, (unsigned char)0);
}
void Image::animation() {
    switch(animaPreset) {
        case LEFT :
            x += dx;
            break;
        case RIGHT :
            x -= dx;
            break;
        case ALPHA :
            alpha += da;
        	if (alpha <= 0)	da = 1;
        	if (alpha >= 0xFF) da = -1;
        	break;
    }
}
       
Text::Text(int x, int y, LPCTSTR outtxt, int preset) {
    this->animaPreset = preset;
    textstring = outtxt;
    this->x = x;
    this->y = y;
    img = newimage(1000, 1000);
    alpha = 255;x = 20; y = 20;dx = 1; da = 1;
    setfont(216, 0,"ºÚÌå",img);
    outtextxy(toCenterX(x), toCenterY(y), textstring, img);
}

//convert the anchor to the cneter of text, for operating easier.
inline int Text::toCenterX(int x) {
    return 2*x - textwidth(textstring);
}

inline int Text::toCenterY(int y) {
    return 2*y - textheight(textstring);
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

void Layer::display(float currentTime) {
    if(currentTime < inTime){
        //wait;
    }else if(currentTime >= inTime && currentTime <= outTime) {
        source->animation();
        cleardevice();
        source->render();
    }else{
        if(source->img != NULL)
            delimage(source->img);
    }
}

Composition::Composition(int n, Layer* layers) {
    numOfLayers = n;
    this->layers =  layers;
}
void Composition::present(float currentTime) {
    for(int i = 0; i < numOfLayers; i++) {
        if(currentTime < layers[i].inTime){
            //wait;
        }else if(currentTime >= layers[i].inTime && currentTime <= layers[i].outTime) {
            layers[i].source->animation();
        }else{
            if(layers[i].source->img != NULL)
                delimage(layers[i].source->img);
        }
    }    
    
    cleardevice();
    
    for(int i = 0; i < numOfLayers; i++) {
        if(currentTime < layers[i].inTime){
            //wait;
        }else if(currentTime >= layers[i].inTime && currentTime <= layers[i].outTime) {
            layers[i].source->render();
        }else{
            if(layers[i].source->img != NULL)
                delimage(layers[i].source->img);
        }
    }
                 
}

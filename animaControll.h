#pragma once
#include <graphics.h>

const int LEFT = 1;
const int RIGHT = 2;
const int ALPHA = 3;
static float current = 0.0;
class Screen {
    public : 
        int width;
        int height;
        Screen(int, int) ;
        ~Screen() ;
        int getWidth() ;
        int getHeight () ;
}; 

class Image {
    public :
        Image();
        ~Image();
        void draw();
        void animation();
        void render();
        void clear();
        PIMAGE img;
        float x, y;
        int r;
    	float dx, dy;
    	int alpha, da;
    	int animaPreset;
    	
}; 

class Text : public Image {
    public : 
        PIMAGE img;
    	LPCTSTR textstring; 
        int txtWidth;
        int txtHeight;
        
        Text(int, int, LPCTSTR, int);
        //convert the anchor to the cneter of text, for operating easier.
        inline int toCenterX(int);
        inline int toCenterY(int);
};

class Layer {
    public :
        float inTime, outTime;
        Image* source;
        Layer();
        Layer(float, float, Image*);
        void init(float, float, Image*);
        void display(float);
};

class Composition {
    public :
        Composition(int, Layer*);
        Layer* layers;
        int numOfLayers;
        void present(float);
};

/****************************************************************************
Copyright (c) 2015- MianTang 

This software is released under the MIT License 
<http://www.opensource.org/licenses/mit-license.php>

****************************************************************************/
#pragma once
#include <graphics.h>

// Preset mode for animation controlling for each Image or Text.
const int LEFT = 1;
const int RIGHT = 2;
const int ALPHA = 3;
const int HOLD = 4;
const int LEFTALPHA = 5;
const int RIGHTALPHA = 6;
const int ALPHAHOLD = 7;

// Combine setcolor and setlinewidth to a single function , for easier converting of Flash code.
void lineStyle(float, color_t, PIMAGE);

/**
* @brief Init screen of EGE.
*/
class Screen {
    private :
        int width;
        int height; 
    public : 
        Screen(int, int) ;
        ~Screen() ;
        int getWidth() ;
        int getHeight() ;
}; 

/**
* @brief Base class for Picture and Text .
*/
class Image {
    public :
        Image();
        ~Image();
        void draw();
        void animation();
        void render();
        PIMAGE img;
        float x, y;
    	float dx, dy;
    	int alpha, da;
    	int animaPreset;
    	bool isCleared;
}; 

/**
* @brief Text element to display on the screen , extend Image .
*/
class Text : public Image {
    public : 
        int txtWidth;
        int txtHeight;
        LPCTSTR textstring;
        
        Text(int, int, LPCTSTR, int);
        //convert the anchor to the cneter of text, for operating easier.
        inline int toCenterX(int);
        inline int toCenterY(int);
};

/**
* @brief Attach timeline to the Image[or its child class] for displaying in its Composition
*/
class Layer {
    public :
        float inTime, outTime;
        Image* source;
        Layer();
        Layer(float, float, Image*);
        void init(float, float, Image*);
};

/**
* @brief Display the Layer(s) contained ,foreach currentTime to present the elements in proper time on the screen.
*/
class Composition {
    public :
        Composition(int, Layer*);
        Layer* layers;
        int numOfLayers;
        void present(float);
//        void setLayer(int, Layer);
};

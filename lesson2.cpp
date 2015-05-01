#include <graphics.h>
#include <windows.h> 
#include <stdlib.h> 
#include "picSources.h"
#include "animaControll.h" 

int main()
{
    Screen screen(800, 600);
    setbkcolor(0xDAD0BD);
    TaijiImg  pic ;
    YSimg pic2;
//    Text t1(200, 200, "ÄãÊÇßÕ»ÒÀÇ", ALPHA);
    Layer* layers;
//    pic.Draw();
//        Text  t(200, 200, "ÄãÊÇßÕ»ÒÀÇ");
//    PlaySound("C:\\WINDOWS\\Media\\Ring03.wav", NULL, SND_FILENAME | SND_ASYNC); 
    layers[0].init(0.0, 2.0, &pic);
    layers[1].init(1.0, 4.0, &pic2);
//    layers[2].init(0.0, 4.0, &t1);
    
    Composition mainComp(2, layers);
    
    float currentTime = 0.0;
    for ( ; is_run(); delay_fps(50) )
	{
	    currentTime += 0.02;

        mainComp.present(currentTime);
        if(currentTime >= 4.0)
            break;
	}
	
	getch();
	closegraph();
	return 0;
}

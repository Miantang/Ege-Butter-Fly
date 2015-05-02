#include <graphics.h>
#include <windows.h> 
#include <stdlib.h> 
#include "picSources.h"
#include "picSources2.h"
#include "picSources3.h"
#include "animaControll.h" 

int main()
{
    Screen screen(848, 480);
    PlaySound("Butter-fly.wav", NULL, SND_FILENAME | SND_ASYNC); 
    
    setbkcolor(0xF1F1F1);
    
    //An Array list short name for layers     
    Layer* l;
    
    //a short name for every single particular Image, declaration in "picSources([1-9])", source pictures are in folder <Picture>
    P1 p1;P2 p2;P3 p3;P4 p4;P5 p5;P6 p6;P7 p7;P8 p8;P9 p9;P10 p10;P11 p11;
    // 滚球兽 Goro Mon 
    C1 c1;C2 c2;C3 c3;C4 c4;C5 c5;C6 c6;
    // 八神太一 Taichi Kamiya
    Taichi1 tc1; Taichi1 tc2; Taichi1 tc3;
    // 石田大和 Yamato Ishida
    Yamato1 ym1; Yamato1 ym2; Yamato1 ym3; 
    // 太刀川美美 Tachikawa Mimi
    Mimi1 mm1; Mimi2 mm2; Mimi3 mm3; Mimi1 mm4; 
    // 泉光子郎 Izumi Koushiro
    Izumi1 iz1; Izumi2 iz2; Izumi3 iz3; 
//    T1 t1;
    Text flowerup(0, 0, "▓◆**★**◆※◆**★**◆※**★**◆※◆**★**◆▓◆**★**◆", HOLD);
    setcolor(0x99FF00, flowerup.img); outtextxy(0, 0, flowerup.textstring, flowerup.img);
    Text flowerbottom(0, 445, "▓◆**★**◆※◆**★**◆※**★**◆※◆**★**◆▓◆**★**◆", HOLD);
    setcolor(0x99FF00, flowerbottom.img); outtextxy(0, 0, flowerbottom.textstring, flowerbottom.img);
    
    RectUp r1;RectBottom r2;
    
    Text t1(424-154, 203, "那是几年前的事情了", ALPHA),t2(424-185, 203, "我与数码宝贝的初次邂逅", ALPHA),
         t3(424-208, 203, "《数码宝贝：Butter-Fly》", ALPHA), t4(424-100, 203, "制作人：面汤", ALPHA);
         
    Text t5(324, 203, "变做开心的蝴蝶", RIGHTALPHA), t6(324, 203, "乘坐在闪耀的风上", RIGHTALPHA);
    Text t7(284, 203, "现在马上", LEFTALPHA), t8(244, 203, "要前去与你会面", LEFTALPHA);
    Text t9(384, 203, "什么多余的事", RIGHTALPHA), t10(384, 203, "还是忘了最好", RIGHTALPHA);
    Text t11(284, 203, "这些完了", LEFTALPHA), t12(244, 203, "再没有时间去嬉戏", LEFTALPHA);
    Text t13(354, 203, "有什麼 WOW WOW WOW WOW WOW", RIGHTALPHA), t14(204, 203, "会到达这天空吧 ", LEFTALPHA);
    Text t15(354, 203, "但是 WOW WOW WOW WOW WOW", RIGHTALPHA), t16(80, 203, "明日的预定也不会知道", LEFTALPHA);
    
   // Init every single Layer to its duration time.
    l[0].init(0, 159.0, &r1);l[1].init(0, 159.0, &r2);l[2].init(0, 159.0, &flowerup);l[3].init(0, 159.0, &flowerbottom);
    
//    l[4].init(0.0, 4.1, &t1);l[5].init(4.2, 9.0, &t2);  l[6].init(9.9, 13.3, &t3); l[7].init(13.7, 19.0, &t4);
//     l[4].init(0.0, 9.0, &p3);l[5].init(0.0, 4.1, &t7);  l[6].init(4.3, 9.0, &t8); 
//    l[4].init(0.0, 4.1, &t9); l[5].init(0.0, 4.1, &p8);  l[6].init(4.3, 9.0, &t10); l[7].init(4.3, 9.0, &p9);
//    l[4].init(0.0, 4.1, &t11); l[5].init(0.0, 4.1, &p10);  l[6].init(4.3, 9.0, &t12); l[7].init(4.3, 9.0, &p11);
//    l[4].init(0.0, 4.1, &t13); l[5].init(0.0, 4.1, &p4);  l[6].init(4.3, 9.0, &t14); l[7].init(4.3, 9.0, &p5);
    l[4].init(0.0, 4.1, &t15); l[5].init(0.0, 4.1, &p6);  l[6].init(4.3, 9.0, &t16); l[7].init(4.3, 9.0, &p7);
    
    l[8].init(20.9, 24.2, &t5); l[9].init(20.9, 24.2, &p1);
    l[10].init(24.9, 28.9, &t6);l[11].init(24.9, 28.9, &p2);
    
    
    Composition mainComp(12, l);
    
    float currentTime = 0.0;
    
    for ( ; is_run(); delay_fps(50) )
	{
	    currentTime += 0.02;
        mainComp.present(currentTime);
        if(currentTime >= 159.0) break;
	}
	
	getch();
	closegraph();
	return 0;
}

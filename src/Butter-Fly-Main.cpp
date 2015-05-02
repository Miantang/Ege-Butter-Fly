#include <graphics.h>
#include <windows.h> 
#include <stdlib.h> 
#include "animaControll.h" 

#include "picSources1.h"
#include "picSources2.h"
#include "picSources3.h"
#include "picSources4.h"

int main()
{
    Screen screen(848, 480);
    PlaySound("sound\\Butter-Fly.wav", NULL, SND_FILENAME | SND_ASYNC); 
    
    setbkcolor(0xF1F1F1);
    
    //a short name for every single particular Image, declaration in "picSources([1-9])", source pictures are in folder <Picture>
    P1 p1;P2 p2;P3 p3;P4 p4;P5 p5;P6 p6;P7 p7;P8 p8;P9 p9;P10 p10;P11 p11;
    // 无限大 的暴龙兽 
    B1 b1;B2 b2;B3 b3;B4 b4;B5 b5;B6 b6;B7 b7;B8 b8;B9 b9;
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
    
    Text t17(414, 203, "在无限大的梦想后面", RIGHTALPHA), t18(100, 203, "这什麼也没有的世界", LEFTALPHA);
    Text t19(484, 203, "亲爱的", RIGHTALPHA), t20(404, 203, "即使我对你的思念比不上你", RIGHTALPHA);
    Text t21(404, 203, "就算有一双满身停留影像的", RIGHTALPHA), t22(464, 203, "不可靠翅膀 ", RIGHTALPHA);
    Text t23(244, 203, "也一定能高飞的", LEFTALPHA), t24(228, 203, "On My Love", LEFTALPHA);
    
    Text t25(424-54, 203, "滚球兽", ALPHA), t26(424-54, 203, "滚球兽", ALPHA);
    Text t27(424-184, 203, "滚球兽，你去哪里了，滚球兽", ALPHA),t28(424-54, 203, "滚球兽", ALPHA);
    
    //An Array list short name for layers     
    Layer l[48];
    
    // Init every single Layer to its duration time.
    l[0].init(0, 159.0, &r1);l[1].init(0, 159.0, &r2);l[2].init(0, 159.0, &flowerup);l[3].init(0, 159.0, &flowerbottom);
    l[4].init(0.0, 3.7, &t1);l[5].init(3.8, 9.0, &t2);  l[6].init(9.4, 13.1, &t3); l[7].init(13.3, 18.5, &t4);
    l[8].init(19.6, 24.0, &t5); l[9].init(19.6, 24.0, &p1); l[10].init(24.3, 28.9, &t6);l[11].init(24.3, 28.9, &p2);
    l[12].init(29.1, 37.8, &p3); l[13].init(29.1, 37.8, &t7);
    l[14].init(31.7, 37.8, &t8); 
    l[15].init(39.5, 42.7, &t9); l[16].init(39.5, 42.7, &p8);  l[17].init(42.9, 47.0, &t10); l[18].init(42.9, 47.0, &p9);
    l[19].init(47.4, 49.1, &t11); l[20].init(47.4, 49.1, &p10);  l[21].init(49.4, 55.5, &t12); l[22].init(49.4, 55.5, &p11);
    l[23].init(56.5, 59.7, &t13); l[24].init(56.5, 59.7, &p4);  l[25].init(60.0, 65.0, &t14); l[26].init(60.0, 65.0, &p5);
    l[27].init(65.3, 70.1, &t15); l[28].init(65.3, 70.1, &p6);  l[29].init(70.3, 77.6, &t16); l[30].init(70.3, 77.6, &p7);
    
    l[31].init(79.5, 85.7 ,&t17); l[32].init(79.5, 85.7, &b1);  l[33].init(86.1, 89.6, &t18); l[34].init(86.1, 89.6, &b2);
    
    l[35].init(90.0, 93.0, &t19); l[36].init(90.0, 93.0, &b3);  l[37].init(93.2, 97.5, &t20); l[38].init(93.2, 97.5, &b4);
    l[39].init(98.0, 104.1, &t21); l[40].init(98.0, 104.1, &b5);  l[41].init(104.3, 108.0, &t22); l[42].init(104.3, 108.0, &b6);
    l[43].init(108.2, 111.3, &t23); l[44].init(108.2, 110.3, &b7);  l[45].init(111.5, 117.0, &t24); l[46].init(110.5, 113.5, &b8);l[47].init(113.5, 117.0, &b9); 

//  l[4].init(0.0, 4.1, &t25); l[5].init(0.0, 9.0, &c1);  l[6].init(4.3, 9.0, &t26); l[7].init(3.0, 9.0, &c2);l[8].init(6.0, 9.0, &c3); 
   
    Composition mainComp(48, l);
    
    float currentTime = 0.0;
    
    for ( ; is_run(); delay_fps(50) )
	{
	    currentTime += 0.02;
//	    if(currentTime >= 0 && currentTime <=29.0 ){
	        mainComp.present(currentTime);
//	    }else if(currentTime > 29.0 && currentTime <=56.0 ){
//	        
//	    }
        
        if(currentTime >= 159.0) break;
	}
	
	getch();
	closegraph();
	return 0;
}

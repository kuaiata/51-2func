#include "oled.h"
//�˵���ʾ

void display_menu2(int menu2_flag,int a,int b,int c,int d) {
		//OLED_Clear();
	switch (menu2_flag) {
    case 1: {
        OLED_ShowString(0, 0, "ax^3");
        OLED_ShowString(0, 2, "bx^2");
				OLED_ShowString(0, 4, "cx");
        OLED_ShowString(0, 6, "d");
        OLED_ShowString(54, 0, "*");
        OLED_ShowString(54, 2, " ");
        OLED_ShowString(54, 4, " ");
        OLED_ShowString(54, 6, " ");
			OLED_ShowNum(90, 0, a,3,16);
        OLED_ShowNum(90, 2, b,3,16);
        OLED_ShowNum(90, 4, c,3,16);
        OLED_ShowNum(90, 6, d,3,16);
    } break;
    case 2: {
        OLED_ShowString(0, 0, "ax^3");
        OLED_ShowString(0, 2, "bx^2");
				OLED_ShowString(0, 4, "cx");
        OLED_ShowString(0, 6, "d");
        OLED_ShowString(54, 0, " ");
        OLED_ShowString(54, 2, "*");
        OLED_ShowString(54, 4, " ");
        OLED_ShowString(54, 6, " ");
			OLED_ShowNum(90, 0, a,3,16);
        OLED_ShowNum(90, 2, b,3,16);
        OLED_ShowNum(90, 4, c,3,16);
        OLED_ShowNum(90, 6, d,3,16);
    } break;
		case 3: {
        OLED_ShowString(0, 0, "ax^3");
        OLED_ShowString(0, 2, "bx^2");
				OLED_ShowString(0, 4, "cx");
        OLED_ShowString(0, 6, "d");
        OLED_ShowString(54, 0, " ");
        OLED_ShowString(54, 2, " ");
        OLED_ShowString(54, 4, "*");
        OLED_ShowString(54, 6, " ");
			OLED_ShowNum(90, 0, a,3,16);
        OLED_ShowNum(90, 2, b,3,16);
        OLED_ShowNum(90, 4, c,3,16);
        OLED_ShowNum(90, 6, d,3,16);
    } break;
		case 4: {
        OLED_ShowString(0, 0, "ax^3");
        OLED_ShowString(0, 2, "bx^2");
				OLED_ShowString(0, 4, "cx");
        OLED_ShowString(0, 6, "d");
        OLED_ShowString(54, 0, " ");
        OLED_ShowString(54, 2, " ");
        OLED_ShowString(54, 4, " ");
        OLED_ShowString(54, 6, "*");
			OLED_ShowNum(90, 0, a,3,16);
        OLED_ShowNum(90, 2, b,3,16);
        OLED_ShowNum(90, 4, c,3,16);
        OLED_ShowNum(90, 6, d,3,16);
    } break;
    }
}

#include "oled.h"
//≤Àµ•œ‘ æ

void display_menu1(int menu1_flag) {
//OLED_Clear();
		switch (menu1_flag) {
    case 1: {
        OLED_ShowString(0, 0, "calc");
        OLED_ShowString(0, 2, "func");
        OLED_ShowString(90, 0, "<-");
        OLED_ShowString(90, 2, "  ");
        OLED_ShowString(90, 4, "  ");
        OLED_ShowString(90, 6, "  ");
    } break;
    case 2: {
        OLED_ShowString(0, 0, "calc");
        OLED_ShowString(0, 2, "func");
        OLED_ShowString(90, 0, "  ");
        OLED_ShowString(90, 2, "<-");
        OLED_ShowString(90, 4, "  ");
        OLED_ShowString(90, 6, "  ");
    } break;
    }
}

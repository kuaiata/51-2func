#include "REG51.h"
#include "oled.h"
#include "menu.h"
int menu22;
int main(void) {    
    OLED_Init();
    while(1) {    
        menu22 = menu1();
        if(menu22==1) menu2_calc();       
        if(menu22==2) menu2_func();         
    }        
}
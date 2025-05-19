#include "REG51.h"
#include "oled.h"
#include "Delay.h"
#include "menu.h"
#include "MatrixKey.h"
#include "display_menu1.h"
#include "display_menu2.h"
#include "display_menu3.h"
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
int menu1_flag = 1;
int menu2_flag = 1;
int a,b,c,d;
int t=0;
int menu1() {
		char key;
		while(1){
			key=MatrixKey();
			if (key== '1') {//����ѡ��˵�
          menu1_flag++;
          if (menu1_flag == 3) menu1_flag = 1;
          display_menu1(menu1_flag);
      }

      if (key == '2' ) {//����ѡ��˵�
          menu1_flag--;
          if (menu1_flag == 0) menu1_flag = 2;
          display_menu1(menu1_flag);
      }
      if (key == '3') {//ȷ�ϼ�����������˵�
          OLED_Clear();
          return menu1_flag;
     }
			display_menu1(menu1_flag);
		}
	}
//��ѧ������
int menu2_calc() {}
//���뺯���Լ���ʾͼ��
int menu2_func() { 
	int menu3_func=0;
	char key;
	while(1){
			key=MatrixKey();
			
			if (key== '1') {//����ѡ��˵�
          menu2_flag++;
          if (menu2_flag == 5) menu2_flag = 1;
          display_menu2(menu2_flag,a,b,c,d);
      }

      if (key == '2' ) {//����ѡ��˵�
          menu2_flag--;
          if (menu2_flag == 0) menu2_flag = 4;
          display_menu2(menu2_flag,a,b,c,d);
      }
      if (key == '3') {//ȷ�ϼ�����������˵�
          OLED_Clear();
          menu3_func=menu2_flag;
     }
			if(key=='C'){OLED_Clear();return 0;}
			if(key=='='){OLED_Clear();menu3_func=menu3_grap();}
			if(menu3_func==1){menu3_func=menu3_a();}
			if(menu3_func==2){menu3_func=menu3_b();}
			if(menu3_func==3){menu3_func=menu3_c();}
			if(menu3_func==4){menu3_func=menu3_d();}
			display_menu2(menu2_flag,a,b,c,d);
}
}
int menu3_a(){
	char key;
	a=0;
	while(1){
			key=MatrixKey();
			if (key== '1')a++;
      if (key == '2')a--;
      if (key == 'C'){OLED_Clear();return 0;}
			display_menu3(1,a,b,c,d);
	}
}
int menu3_b(){
	char key;
	b=0;
	while(1){
			key=MatrixKey();
			if (key== '1')b++;
      if (key == '2')b--;
      if (key == 'C'){OLED_Clear();return 0;}
			display_menu3(2,a,b,c,d);
	}
}
int menu3_c(){
	char key;
	c=0;
	while(1){
			key=MatrixKey();
			if (key== '1')c++;
      if (key == '2')c--;
      if (key == 'C'){OLED_Clear();return 0;}
			display_menu3(3,a,b,c,d);
	}
}
int menu3_d(){
	char key;
	d=0;
	while(1){
			key=MatrixKey();
			if (key== '1')d++;
      if (key == '2')d--;
      if (key == 'C'){OLED_Clear();return 0;}
			display_menu3(4,a,b,c,d);
	}
}

int min(int a, int b) {return (a < b) ? a : b;}
int max(int a, int b) {return (a > b) ? a : b;}

int menu3_grap() {
    unsigned char x, y;
    long temp, math_x, x_sq;
    int x_offset = 64, y_offset = 32;//ƫ����
    int y_scale_num = 10;//y������ϵ��
    char key;
    bit need_redraw = 1;//�ػ��־

    #define X_SCALE 8//x������ϵ��
    #define Y_SCALE 2//y������ϵ��
    #define MAX_Y_SCALE 40//���y������ϵ��
    #define MIN_Y_SCALE 4//��Сy������ϵ��

    while (1) {
        if (need_redraw) {
            OLED_Clear();
            for (x = 0; x < 128; x++) {//����x
							//����x����
                math_x = (x - x_offset) * 10L / X_SCALE;
                x_sq = (math_x * math_x) / 10L;
							//����yֵ
                temp = (a * math_x * x_sq) / 1000L + (b * x_sq) / 10L + c * math_x + d * 10L;
                //����y����
                y = y_offset - (temp * y_scale_num) / (Y_SCALE * 10L);
                //�߽�
                if (y >= 63) continue;  
                if (y < 0) y = 0;     
                //���Ƶ�
                OLED_DrawPoint(x, y, 1);
            }
            need_redraw = 0;
        }
				if ((key = MatrixKey()) != 0) {
            switch(key) {
                case '1': y_scale_num = min(y_scale_num + 1, MAX_Y_SCALE); break;//�Ŵ�y
                case '2': y_scale_num = max(y_scale_num - 1, MIN_Y_SCALE); break;//��Сy
                case '4': x_offset = max(x_offset - 5, -30); break;//����
                case '5': x_offset = min(x_offset + 5, 150); break;//����
                case '7': y_offset = max(y_offset - 3, 5);break;//����
                case '8': y_offset = min(y_offset + 3, 60);break;//����
                case 'C': OLED_Clear(); return 0;//����
                default: continue;
            }
            need_redraw = 1;
            Delay(20);
        }
        Delay(10);
    }
}
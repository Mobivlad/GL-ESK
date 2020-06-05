#include "main.h"
int8_t mode = -1;
int main()
{
	initDelay();
	initEXTI();
	initLCD();
	while(1){
		switch(mode){
			case 0:
				clear();
				lcdString("Text1");
				mode = -1;
				break;
			case 1:
				clear();
				lcdString("Text2");
				mode = -1;
				break;
			case 2:
				clear();
				lcdString("Text3");
				mode = -1;
				break;
			case 3:
				clear();
				lcdString("Text4");
				mode = -1;
				break;
			case 4:	
				clear();
				lcdString("Text5");
				mode = -1;
				break;
		}
	}
}

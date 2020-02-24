#include "main.h"
int8_t mode = -1;
int main()
{
	initDelay();
	initButtons();
	initLCDPins();
	initLCD();
	while(1){
		if(SW0Pressed() && mode!=1){
			clear();
			lcdString("SWT1 Pressed");
			mode = 1;
		}
		if(SW1Pressed()&& mode!=2){
			clear();
			lcdString("SWT2 Pressed");
			mode = 2;
		}
		if(SW2Pressed()&& mode!=3){
			clear();
			lcdString("SWT3 Pressed");
			mode = 3;
		}
		if(SW3Pressed()&& mode!=4){
			clear();
			lcdString("SWT4 Pressed");
			mode=4;
		}
		if(SW4Pressed()&& mode!=5){
			clear();
			lcdString("SWT5 Pressed");
			mode=5;
		}
	}
}

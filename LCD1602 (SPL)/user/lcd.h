#ifndef LCD_H
#define LCD_H

#include "stm32f4xx.h"
#include "delay.h"

#define lcdPort  GPIOE
#define rsPin  GPIO_Pin_7
#define rwPin  GPIO_Pin_10
#define enPin  GPIO_Pin_11
#define dh4Pin  GPIO_Pin_12
#define dh5Pin  GPIO_Pin_13
#define dh6Pin  GPIO_Pin_14
#define dh7Pin  GPIO_Pin_15

#define RS(X) if(X){GPIO_SetBits(lcdPort,rsPin);} else {GPIO_ResetBits(lcdPort,rsPin);}
#define RW(X) if(X){GPIO_SetBits(lcdPort,rwPin);} else {GPIO_ResetBits(lcdPort,rwPin);}
#define EN(X) if(X){GPIO_SetBits(lcdPort,enPin);} else {GPIO_ResetBits(lcdPort,enPin);}
#define DH4(X) if(X){GPIO_SetBits(lcdPort,dh4Pin);} else {GPIO_ResetBits(lcdPort,dh4Pin);}
#define DH5(X) if(X){GPIO_SetBits(lcdPort,dh5Pin);} else {GPIO_ResetBits(lcdPort,dh5Pin);}
#define DH6(X) if(X){GPIO_SetBits(lcdPort,dh6Pin);} else {GPIO_ResetBits(lcdPort,dh6Pin);}
#define DH7(X) if(X){GPIO_SetBits(lcdPort,dh7Pin);} else {GPIO_ResetBits(lcdPort,dh7Pin);}

void initLCDPins(void);
void initLCD(void);
void lcdSend(uint8_t, uint8_t);
void lcdCommand(uint8_t);
void lcdChar(const char);
void lcdString(char*);
void setCursor(uint8_t, uint8_t);
void parametrsToggle(uint8_t, uint8_t, uint8_t);
void shiftToggle(uint8_t, uint8_t);
void scrollRight(void);
void scrollLeft(void);
void clear(void);
void home(void);

#endif //LCD_H

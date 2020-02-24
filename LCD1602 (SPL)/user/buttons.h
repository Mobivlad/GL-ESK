#ifndef BUTTONS_H
#define BUTTONS_H

#include "stm32f4xx.h"

#define SW0_PORT GPIOC
#define SW1_PORT GPIOA
#define SW2_PORT GPIOC
#define SW3_PORT GPIOC
#define SW4_PORT GPIOC
#define SW0_PIN GPIO_Pin_11
#define SW1_PIN GPIO_Pin_15
#define SW2_PIN GPIO_Pin_9
#define SW3_PIN GPIO_Pin_6
#define SW4_PIN GPIO_Pin_8


void initButtons(void);
uint8_t SW0Pressed(void);
uint8_t SW1Pressed(void);
uint8_t SW2Pressed(void);
uint8_t SW3Pressed(void);
uint8_t SW4Pressed(void);

#endif //BUTTONS_H

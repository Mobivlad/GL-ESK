#include "buttons.h"

void initButtons (void)
{
	GPIO_InitTypeDef 	GPIO_Init_Struct;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
	
	GPIO_Init_Struct.GPIO_Pin = SW0_PIN|SW2_PIN|SW3_PIN;
	GPIO_Init_Struct.GPIO_Mode = GPIO_Mode_IN;
	GPIO_Init_Struct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init_Struct.GPIO_OType = GPIO_OType_PP;
	GPIO_Init_Struct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(SW0_PORT, &GPIO_Init_Struct);
	
	GPIO_Init_Struct.GPIO_Pin = SW1_PIN;
	GPIO_Init_Struct.GPIO_Mode = GPIO_Mode_IN;
	GPIO_Init_Struct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init_Struct.GPIO_OType = GPIO_OType_PP;
	GPIO_Init_Struct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(SW1_PORT, &GPIO_Init_Struct);
}

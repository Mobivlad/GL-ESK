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

uint8_t SW0Pressed(void){
	return GPIO_ReadInputDataBit(SW0_PORT,SW0_PIN)==Bit_RESET;
}

uint8_t SW1Pressed(void){
	return GPIO_ReadInputDataBit(SW1_PORT,SW1_PIN)==Bit_RESET;
}

uint8_t SW2Pressed(void){
	return GPIO_ReadInputDataBit(SW2_PORT,SW2_PIN)==Bit_RESET;
}

uint8_t SW3Pressed(void){
	return GPIO_ReadInputDataBit(SW3_PORT,SW3_PIN)==Bit_RESET;
}

uint8_t SW4Pressed(void){
	return GPIO_ReadInputDataBit(SW4_PORT,SW4_PIN)==Bit_RESET;
}

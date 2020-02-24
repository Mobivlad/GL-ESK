#include "spi.h"

void initSPI (void)
{
	GPIO_InitTypeDef 	GPIO_Init_Struct;
	SPI_InitTypeDef		SPI_Init_user;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	
	GPIO_Init_Struct.GPIO_Pin = GPIO_Pin_5;
	GPIO_Init_Struct.GPIO_Mode = GPIO_Mode_AF;
	GPIO_Init_Struct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init_Struct.GPIO_OType = GPIO_OType_PP;
	GPIO_Init_Struct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOA, &GPIO_Init_Struct);
	
	GPIO_Init_Struct.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_5;
	GPIO_Init_Struct.GPIO_Mode = GPIO_Mode_AF;
	GPIO_Init_Struct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init_Struct.GPIO_OType = GPIO_OType_PP;
	GPIO_Init_Struct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOB, &GPIO_Init_Struct);
	
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource5, GPIO_AF_SPI1);
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource4, GPIO_AF_SPI1);
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource5, GPIO_AF_SPI1);
	
	
	GPIO_Init_Struct.GPIO_Pin = GPIO_Pin_7;
	GPIO_Init_Struct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_Init_Struct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init_Struct.GPIO_OType = GPIO_OType_PP;
	GPIO_Init_Struct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOD, &GPIO_Init_Struct);
	
	GPIO_SetBits(GPIOD,GPIO_Pin_7);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);
	SPI_Init_user.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
	SPI_Init_user.SPI_Mode = SPI_Mode_Master;
	SPI_Init_user.SPI_DataSize = SPI_DataSize_8b;
	SPI_Init_user.SPI_CPOL = SPI_CPOL_Low;
	SPI_Init_user.SPI_CPHA = SPI_CPHA_1Edge;
	SPI_Init_user.SPI_NSS = SPI_NSS_Soft;
	SPI_Init_user.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_64;
	SPI_Init_user.SPI_FirstBit = SPI_FirstBit_MSB;
	SPI_Init_user.SPI_CRCPolynomial = 7;
	SPI_Init(SPI1, &SPI_Init_user);
	SPI_Cmd(SPI1, ENABLE);

}

void SendByte(uint8_t data){
	while(SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_BSY) == SET){}
  SPI_I2S_SendData(SPI1, data);
  while(SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_BSY) == SET){}
	SPI_I2S_ReceiveData(SPI1);
}

uint8_t ReceiveByte(void){
	while(SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_BSY) == SET){}
  SPI_I2S_SendData(SPI1, 0x00);
  while(SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_BSY) == SET){}
	return SPI_I2S_ReceiveData(SPI1);
}

#include "spi.h"

#define MODE1

extern ARM_DRIVER_SPI Driver_SPI1;

ARM_DRIVER_SPI* SPIdrv = &Driver_SPI1;
uint32_t x;
void initSPI (void)
{
	//CS initialization
	RCC->AHB1ENR|=RCC_AHB1ENR_GPIODEN; //enable rcc
	GPIOD->MODER|=0x4000; //set PIN7 out
	GPIOD->ODR |= GPIO_PIN_7;	//SET 1
	
	//spi initialization
	SPIdrv->Initialize(NULL);
  SPIdrv->PowerControl(ARM_POWER_FULL);
  x = SPIdrv->Control(ARM_SPI_MODE_MASTER | ARM_SPI_CPOL0_CPHA0 | ARM_SPI_MSB_LSB | ARM_SPI_SS_MASTER_UNUSED | ARM_SPI_DATA_BITS(8), 100000);
}

void SendByte(uint8_t data){
	SPIdrv->Send(&data,1);
	while(SPIdrv->GetStatus().busy);
}

uint8_t ReceiveByte(void){
	uint8_t data=0x00;
	SPIdrv->Receive(&data,1);
	while(SPIdrv->GetStatus().busy);
	return data;
}

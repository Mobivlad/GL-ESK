#include "spi.h"

#define MODE2

extern ARM_DRIVER_SPI Driver_SPI1;

ARM_DRIVER_SPI* SPIdrv = &Driver_SPI1;

void initSPI (void)
{
	//CS initialization
	RCC->AHB1ENR|=RCC_AHB1ENR_GPIODEN; //enable rcc
	GPIOD->MODER|=0x10>>2; //set PIN7 out
	GPIOD->ODR |= GPIO_PIN_7;	//SET 1
	
	//spi initialization
	SPIdrv->Initialize(NULL);
  SPIdrv->PowerControl(ARM_POWER_FULL);
  SPIdrv->Control(ARM_SPI_MODE_MASTER | ARM_SPI_CPOL0_CPHA0 | ARM_SPI_MSB_LSB | ARM_SPI_SS_MASTER_SW | ARM_SPI_DATA_BITS(8), 10000000);
}

void SendByte(uint8_t data){
#ifdef MODE1
	
	SPIdrv->Send(&data,1);
	
#elif defined(MODE2)

	uint8_t _data=data;
	SPIdrv->Send(&_data,1);
	while(SPIdrv->GetStatus().busy);
	SPIdrv->Receive(&_data,1);
	while(SPIdrv->GetStatus().busy);

#endif

}

uint8_t ReceiveByte(void){
	uint8_t data=0x00;
#ifdef MODE1

	SPIdrv->Receive(&data,1);

#elif defined(MODE2)

	SPIdrv->Send(&data,1);
	while(SPIdrv->GetStatus().busy);
	SPIdrv->Receive(&data,1);
	while(SPIdrv->GetStatus().busy);
	return data;

#endif

}

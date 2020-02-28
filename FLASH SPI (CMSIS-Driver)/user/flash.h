#ifndef FLASH_H
#define FLASH_H

#include "stm32f4xx_hal.h"              // Keil::Device:STM32Cube HAL:Common
#include "delay.h"

#define BYTE_PROGRAM 0x02
#define READ_COMMAND 0x03
#define RDSR 0x05
#define EWSR 0x50
#define WRSR 0x01
#define WREN 0x06
#define WRDI 0x04
#define AAI_COMMAND 0xAD
#define FERASE_COMMAND 0x60
#define SERASE_COMMAND 0x20
	
void SendByte(uint8_t);
uint8_t ReceiveByte(void);

void ReadDataArrayFromAddress(uint32_t,uint8_t*,uint16_t);
uint8_t ReadStatusRegister(void);
void WriteDataArray(uint32_t,uint8_t*,uint8_t);
void WriteDataArrayWithAAI(uint32_t,uint8_t*,uint8_t);
void WaitUntilBusy(void);
void WriteToStatusRegister(uint8_t);
void DisableWrite(void);
void EnableWrite(void);
void WriteDataToAddress(uint32_t,uint8_t);

void ClearSector(uint32_t);
void FullClear(void);
void setAddress(uint32_t);


#endif

#include "flash.h"

void disableFlash(void)
{
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_7,GPIO_PIN_SET);
}

void enableFlash(void)
{
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_7,GPIO_PIN_RESET);
}


void WriteDataToAddress(uint32_t address,uint8_t data){	
	EnableWrite();
  __nop();
  enableFlash();
  SendByte(BYTE_PROGRAM);
  setAddress(address);
  SendByte(data);
  disableFlash();
  WaitUntilBusy();
}

void setAddress(uint32_t addr){
	SendByte(addr >> 16);
  SendByte(addr >> 8);  
  SendByte(addr);
}


uint8_t ReadStatusRegister(void){
	uint8_t data = 0;
	enableFlash();
  SendByte(RDSR);
  data = ReceiveByte();
  disableFlash();
	return data;
}

void WaitUntilBusy(void){
	
  while (1)
  {
    if ((ReadStatusRegister()&0x01)!=0x01) break;
    __nop();
  }
}

void WriteToStatusRegister(uint8_t statusData){
	enableFlash();
	SendByte(EWSR);	
	disableFlash();
	enableFlash();
	SendByte(WRSR);
	SendByte(statusData);
	disableFlash();
}

void DisableWrite(void){
	enableFlash();
  SendByte(WRDI);
  disableFlash();
}

void EnableWrite(void){
	enableFlash();
  SendByte(WREN);
  disableFlash();
}

void WriteDataArrayWithAAI(uint32_t address,uint8_t* data,uint8_t len){
	EnableWrite();
  __nop();
	enableFlash();
	SendByte(AAI_COMMAND);
	setAddress(address);
	SendByte(data[0]);
	SendByte(data[1]);
	disableFlash();
	WaitUntilBusy();
	for(uint16_t i=1;i<len/2;i++){
		enableFlash();
		SendByte(AAI_COMMAND);
		SendByte(data[i*2]);
		SendByte(data[i*2+1]);
		disableFlash();
		WaitUntilBusy();
	}
	if(len%2==1){
		enableFlash();
		SendByte(AAI_COMMAND);
		SendByte(data[len-2]);
		SendByte(0xFF);
		disableFlash();
		WaitUntilBusy();
	}
	DisableWrite();
	WaitUntilBusy();
}

void WriteDataArray(uint32_t address,uint8_t* data,uint8_t len){
	for(uint16_t i=0;i<len;i++){
		WriteDataToAddress(address+i,data[i]);
	}
}

void ReadDataArrayFromAddress(uint32_t address,uint8_t* dest,uint16_t count){
	enableFlash();
	SendByte(READ_COMMAND);
	setAddress(address);
	for(uint16_t i=0;i<count;i++){ 
		dest[i]=ReceiveByte();
	}
	disableFlash();
}

void ClearSector(uint32_t address){
	EnableWrite();
	__nop();
	enableFlash();
	SendByte(SERASE_COMMAND);
	setAddress(address);
	disableFlash();
	DelayMs(20);
}

void FullClear(void){
	EnableWrite();
  __nop();
  enableFlash();
  SendByte(FERASE_COMMAND);
  disableFlash();
  WaitUntilBusy();
  DelayMs(40);
}

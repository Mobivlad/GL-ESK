#include "main.h"                // Device header

uint8_t rData[10]={0};
int main()
{
	initDelay();
	initSPI();
	WriteToStatusRegister(0);
	FullClear();
	WriteDataArrayWithAAI(0x000000,dataPacket,10);
	ReadDataArrayFromAddress(0x000000,rData,10);
	while(1);
}

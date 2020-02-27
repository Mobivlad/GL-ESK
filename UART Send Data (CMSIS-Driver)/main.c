#include "Driver_USART.h"
#include <stdio.h>
#include <string.h>

extern ARM_DRIVER_USART Driver_USART1;
static ARM_DRIVER_USART * USARTdrv = &Driver_USART1;

int main(){
		USARTdrv->Initialize(NULL);
    /*Power up the USART peripheral */
    USARTdrv->PowerControl(ARM_POWER_FULL);
    /*Configure the USART to 4800 Bits/sec */
    USARTdrv->Control(ARM_USART_MODE_ASYNCHRONOUS |
                      ARM_USART_DATA_BITS_8 |
                      ARM_USART_PARITY_NONE |
                      ARM_USART_STOP_BITS_1 |
                      ARM_USART_FLOW_CONTROL_NONE, 4800);
     
    /* Enable Receiver and Transmitter lines */
    USARTdrv->Control (ARM_USART_CONTROL_TX, 1);
    USARTdrv->Control (ARM_USART_CONTROL_RX, 1);
 
    USARTdrv->Send("\nPress Enter to receive a message", 34);
	while(1){
	}
}
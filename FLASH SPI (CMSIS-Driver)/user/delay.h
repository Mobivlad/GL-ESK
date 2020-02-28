#ifndef DELAY_H
#define DELAY_H
 
#include "stm32f4xx_hal.h"              // Keil::Device:STM32Cube HAL:Common

 
void initDelay(void);
void DelayUs(uint32_t us);
void DelayMs(uint32_t ms);
 
#endif

#ifndef SPI_H
#define SPI_H

#include "stm32f4xx_hal.h"              // Keil::Device:STM32Cube HAL:Common
#include "Driver_SPI.h"                 // ::CMSIS Driver:SPI


void initSPI(void);
void disableFlash(void);
void enableFlash(void);

#endif

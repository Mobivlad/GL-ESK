#ifndef SPI_H
#define SPI_H

#include "stm32f4xx.h"                  // Device header

void initSPI(void);
void disableFlash(void);
void enableFlash(void);

#endif

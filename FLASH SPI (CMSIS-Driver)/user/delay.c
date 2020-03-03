#include "delay.h"
 
uint32_t usTicks;
 
void SysTick_Handler()
{
    if (usTicks != 0)usTicks--;
}
 
void initDelay()
{
    SystemCoreClockUpdate();
    SysTick_Config(SystemCoreClock / 1000);
}
 
void DelayMs(uint32_t ms)
{
    usTicks = ms;
    while (usTicks);
}

#include "system.h"
#include "ethernet.h"
#include "stm32f4xx_tim.h"
#include "stm32f4xx_rcc.h"



void system_initialize(void)
{
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure; 
    
    RCC_PCLK1Config(RCC_HCLK_Div1);
    RCC_PCLK2Config(RCC_HCLK_Div1);
    
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA | RCC_AHB1Periph_GPIOB |
                           RCC_AHB1Periph_GPIOC | RCC_AHB1Periph_GPIOI |
                           RCC_AHB1Periph_GPIOG | RCC_AHB1Periph_GPIOH |
                           RCC_AHB1Periph_GPIOF | RCC_AHB1Periph_GPIOE,
                           ENABLE);

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2 | RCC_APB1Periph_TIM3 | 
                           RCC_APB1Periph_TIM4 | RCC_APB1Periph_TIM5 |
                           RCC_APB1Periph_TIM12,
                           ENABLE);
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1 | RCC_APB2Periph_SYSCFG |
                           RCC_APB2Periph_TIM8 | RCC_APB2Periph_TIM9,
                           ENABLE);
    
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_ETH_MAC | RCC_AHB1Periph_ETH_MAC_Tx |
                           RCC_AHB1Periph_ETH_MAC_Rx, 
                           ENABLE);
    
        
    ethernet_initialize();
    
    // System timer
    TIM_TimeBaseStructure.TIM_Prescaler = (SystemCoreClock / 1e6) - 1;
    TIM_TimeBaseStructure.TIM_Period = 0xFFFFFFFF;
    TIM_TimeBaseStructure.TIM_ClockDivision = 0;
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

    TIM_Cmd(TIM2, ENABLE);    
}



uint system_time(void)
{
    return TIM2->CNT;
}

u32 sys_now(void)
{
  return TIM2->CNT;
}



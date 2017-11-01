#include "system.h"
  





void SystemInit(void) {
#if (__FPU_PRESENT == 1) && (__FPU_USED == 1)
SCB->CPACR |= ((3UL << 10*2)|(3UL << 11*2));  /* set CP10 and CP11 Full Access */
#endif

RCC->CR |= RCC_CR_HSION;
while (!(RCC->CR & RCC_CR_HSIRDY)){};

RCC->CFGR |= RCC_CFGR_PLLMULL9|RCC_CFGR_PLLSRC_HSI_PREDIV;

RCC->CR |= RCC_CR_PLLON;

while((RCC->CR & RCC_CR_PLLRDY) == 0){}
FLASH->ACR |= FLASH_ACR_LATENCY_1;
RCC->CFGR |= RCC_CFGR_SW_PLL;
while ((RCC->CFGR & (uint32_t)RCC_CFGR_SWS) != (uint32_t)RCC_CFGR_SWS_PLL){}


SysTick_Config(72000000/1000/8);
SysTick->CTRL &= ~SysTick_CTRL_CLKSOURCE_Msk;
}





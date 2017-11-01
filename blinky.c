#include "stm32f30x.h"
#include "delay.h"
#include <stdio.h>
#include "system.h"



int main (void) {
SystemInit();
RCC->AHBENR|= RCC_AHBENR_GPIOAEN;
GPIOA->MODER |= GPIO_MODER_MODER5_0;
	
while(1){
	
	GPIOA->BSRR = GPIO_BSRR_BS_5;
	
	Delay(1000);
	GPIOA->BSRR = GPIO_BSRR_BR_5;
	Delay(1000);

}
	}


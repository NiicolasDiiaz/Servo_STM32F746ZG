#include <stdio.h>
#include "STM32F7xx.h"
#include <math.h>

int  paso=0;

extern "C"{
	void SysTick_Handler (void){
		paso++;
	}
}

int main (void){
	RCC->AHB1ENR=0xFF;
	
	GPIOC->MODER=0x55;
	GPIOC->OTYPER=0;
	GPIOC->OSPEEDR=0x555555;
	GPIOC->PUPDR=0x10000000;
	
	SystemCoreClockUpdate();
	SysTick_Config(SystemCoreClock/10000);
	
	while(true){
		paso=0;
		GPIOC->ODR=1;
		while(paso<10);
		paso=0;
		GPIOC->ODR=0;
		while(paso<200);
	}	
}
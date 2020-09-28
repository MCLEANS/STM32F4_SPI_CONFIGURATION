#include "stm32f4xx.h"
#include "clockconfig.h"
#include "SPI.h"

custom_libraries::clock_config system_clock;
custom_libraries::_SPI spi(SPI2,GPIOB,13,15,14,64,false,true,true);


int main() {
	system_clock.initialize();

	 RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	//SET PA4 to general purpose output
	GPIOA->MODER &= ~GPIO_MODER_MODER4;
	GPIOA->MODER |= GPIO_MODER_MODER4_0;

	GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR4;

	GPIOA->ODR |= GPIO_ODR_ODR_4;

    while(1){
	
		GPIOA->ODR &= ~GPIO_ODR_ODR_4;
		spi.write('K');
		GPIOA->ODR |= GPIO_ODR_ODR_4;
		for(volatile int i = 0; i < 10; i++){} //SMALL DELAY
		GPIOA->ODR &= ~GPIO_ODR_ODR_4;
		spi.write('I');
		GPIOA->ODR |= GPIO_ODR_ODR_4;
		for(volatile int i = 0; i < 10; i++){} //SMALL DELAY
		GPIOA->ODR &= ~GPIO_ODR_ODR_4;
		spi.write('M');
		GPIOA->ODR |= GPIO_ODR_ODR_4;
		for(volatile int i = 0; i < 10; i++){} //SMALL DELAY
	
	}
}

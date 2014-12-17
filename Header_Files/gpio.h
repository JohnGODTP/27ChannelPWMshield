#ifndef __GPIO_H__
#define __GPIO_H__


#include "stm32f10x.h"


#define _GpioInitialAsGPPOutput(Port,HorL,Pin) \
	do{\
			 RCC->APB2ENR |= RCC_APB2ENR_IOP##Port##EN; \
		   GPIO##Port->BSRR |= GPIO_BSRR_BS##Pin;\
		   GPIO##Port->CR##HorL &= ~GPIO_CR##HorL##_CNF##Pin;\
		   GPIO##Port->CR##HorL |= GPIO_CR##HorL##_MODE##Pin;\
		}while(0)

#define _GpioInitialAsGODOutput(Port,HorL,Pin) \
	do{\
			 RCC->APB2ENR |= RCC_APB2ENR_IOP##Port##EN; \
		   GPIO##Port->BSRR |= GPIO_BSRR_BS##Pin;\
		   GPIO##Port->CR##HorL &= ~GPIO_CR##HorL##_CNF##Pin;\
		   GPIO##Port->CR##HorL |= GPIO_CR##HorL##_CNF##Pin##_0;\
		   GPIO##Port->CR##HorL |= GPIO_CR##HorL##_MODE##Pin;\
		}while(0)
		
		
		
#define _GpioInitialAsAFPPOutput(Port,HorL,Pin) \
	do{\
			 RCC->APB2ENR |= RCC_APB2ENR_IOP##Port##EN; \
		   GPIO##Port->BSRR |= GPIO_BSRR_BS##Pin;\
		   GPIO##Port->CR##HorL &= ~GPIO_CR##HorL##_CNF##Pin;\
		   GPIO##Port->CR##HorL |= GPIO_CR##HorL##_CNF##Pin##_1;\
		   GPIO##Port->CR##HorL |= GPIO_CR##HorL##_MODE##Pin;\
		}while(0)
	
		
#define _GpioInitialAsAFODOutput(Port,HorL,Pin) \
	do{\
			 RCC->APB2ENR |= RCC_APB2ENR_IOP##Port##EN; \
		   GPIO##Port->BSRR |= GPIO_BSRR_BS##Pin;\
		   GPIO##Port->CR##HorL |= GPIO_CR##HorL##_CNF##Pin;\
		   GPIO##Port->CR##HorL |= GPIO_CR##HorL##_MODE##Pin;\
		}while(0)
	
		
#define _GpioInitialAsFInput(Port,HorL,Pin) \
	do{\
			 RCC->APB2ENR |= RCC_APB2ENR_IOP##Port##EN; \
		   GPIO##Port->BSRR |= GPIO_BSRR_BS##Pin;\
			 GPIO##Port->CR##HorL &= (~GPIO_CR##HorL##_CNF##Pin);\
		   GPIO##Port->CR##HorL &= ~GPIO_CR##HorL##_MODE##Pin;\
		   GPIO##Port->CR##HorL |= GPIO_CR##HorL##_CNF##Pin##_0;\
		}while(0)
		
#define _GpioInitialAsPInput(Port,HorL,Pin) \
	do{\
			 RCC->APB2ENR |= RCC_APB2ENR_IOP##Port##EN; \
		   GPIO##Port->BSRR |= GPIO_BSRR_BS##Pin;\
			 GPIO##Port->CR##HorL &= (~GPIO_CR##HorL##_CNF##Pin);\
		   GPIO##Port->CR##HorL &= ~GPIO_CR##HorL##_MODE##Pin;\
		   GPIO##Port->CR##HorL |= GPIO_CR##HorL##_CNF##Pin##_1;\
		}while(0)

#define _GpioInitialAsAnInput(Port,HorL,Pin) \
	do{\
			 RCC->APB2ENR |= RCC_APB2ENR_IOP##Port##EN; \
		   GPIO##Port->BSRR |= GPIO_BSRR_BS##Pin;\
			 GPIO##Port->CR##HorL &= (~GPIO_CR##HorL##_CNF##Pin);\
		   GPIO##Port->CR##HorL &= ~GPIO_CR##HorL##_MODE##Pin;\
		}while(0)


#define _GpioClr(port,pin) GPIO##port->BRR |= GPIO_BRR_BR##pin
#define _GpioSet(port,pin) GPIO##port->BSRR |= GPIO_BSRR_BS##pin
#define _GpioReversal(port,pin)	GPIO##port->ODR ^= GPIO_ODR_ODR##pin
#define _GpioPolling(port,pin)	(GPIO##port->IDR & GPIO_IDR_IDR##pin)?1:0



#endif


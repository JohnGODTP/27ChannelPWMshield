#include "hardware_pwm.h"

HDPWM::HDPWM()
{

}

void HDPWM::Initial(BOOL Polarity, U16 frequency,U16 duty)
{
	U8 index;

	
	//enable timer's clock
	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
	RCC->APB1ENR |= (RCC_APB1ENR_TIM2EN | 
	                 RCC_APB1ENR_TIM3EN | 
	                 RCC_APB1ENR_TIM4EN);
	
	RCC->APB1RSTR |= (RCC_APB1RSTR_TIM2RST | 
	                  RCC_APB1RSTR_TIM3RST | 
	                  RCC_APB1RSTR_TIM4RST);
	RCC->APB2RSTR |= RCC_APB2RSTR_TIM1RST;
	delay_us(10);
	RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM2RST | 
	                  RCC_APB1RSTR_TIM3RST | 
	                  RCC_APB1RSTR_TIM4RST);
	RCC->APB2RSTR &= ~RCC_APB2RSTR_TIM1RST;

	for(index = 0;index <4;index ++)Timer[index] = TIM1;	
  //PCLK2=72MHZ
  TIM1->DIER=0x0000;//disable all interrupt enable
	TIM1->PSC = (U16)(TIMER1_CLK/2000000) - 1;  //0.5us/tick
  TIM1->ARR=(U16)(2000000/frequency);
	TIM1->CCER = Polarity ? 0x2222:0x0000;
	TIM1->SR = 0x0000;
  TIM1->CR1=0x0084;//Counter used as up
	TIM1->CCMR1 = 0x7878;
	TIM1->CCMR2 = 0x7878;
	TIM1->CCR1 = ((U32)TIM1->ARR)*duty/10000;
	TIM1->CCR2 = TIM1->CCR1;
	TIM1->CCR3 = TIM1->CCR1;
	TIM1->CCR4 = TIM1->CCR1;
	TIM1->BDTR = TIM_BDTR_MOE;
	//TIM1->CCER = 0x0000;
	for(;index <8;index ++)Timer[index] = TIM2;
  //CLK=72MHZ
  TIM2->DIER=0x0000;//disable all interrupt enable
	TIM2->PSC = (U16)(TIMER2_CLK/2000000) - 1;  //0.5us/tick
  TIM2->ARR=(U16)(2000000/frequency);
	TIM2->CCER = Polarity ? 0x2222:0x0000;
	TIM2->SR = 0x0000;
  TIM2->CR1=0x0084;//Counter used as up
	TIM2->CCMR1 = 0x7878;
	TIM2->CCMR2 = 0x7878;
	TIM2->CCR1 = ((U32)TIM2->ARR)*duty/10000;
	TIM2->CCR2 = TIM2->CCR1;
	TIM2->CCR3 = TIM2->CCR1;
	TIM2->CCR4 = TIM2->CCR1;
	for(;index <12;index ++)Timer[index] = TIM3;
  //CLK=72MHZ
  TIM3->DIER=0x0000;//disable all interrupt enable
	TIM3->PSC = (U16)(TIMER3_CLK/2000000) - 1;  //0.5us/tick
  TIM3->ARR=(U16)(2000000/frequency);
	TIM3->CCER = Polarity ? 0x2222:0x0000;
	TIM3->SR = 0x0000;
  TIM3->CR1=0x0084;//Counter used as up
	TIM3->CCMR1 = 0x7878;
	TIM3->CCMR2 = 0x7878;
	TIM3->CCR1 = ((U32)TIM3->ARR)*duty/10000;
	TIM3->CCR2 = TIM3->CCR1;
	TIM3->CCR3 = TIM3->CCR1;
	TIM3->CCR4 = TIM3->CCR1;
	
	for(;index <16;index ++)Timer[index] = TIM4;
  //CLK=72MHZ
  TIM4->DIER=0x0000;//disable all interrupt enable
	TIM4->PSC = (U16)(TIMER4_CLK/2000000) - 1;  //0.5us/tick
  TIM4->ARR=(U16)(2000000/frequency);
	TIM4->CCER = Polarity ? 0x2222:0x0000;
	TIM4->SR = 0x0000;
  TIM4->CR1=0x0084;//Counter used as up
	TIM4->CCMR1 = 0x7878;
	TIM4->CCMR2 = 0x7878;
	TIM4->CCR1 = ((U32)TIM4->ARR)*duty/10000;
	TIM4->CCR2 = TIM4->CCR1;
	TIM4->CCR3 = TIM4->CCR1;
	TIM4->CCR4 = TIM4->CCR1;
	
	TIM1->CR1 |= TIM_CR1_CEN;
	TIM2->CR1 |= TIM_CR1_CEN;
	TIM3->CR1 |= TIM_CR1_CEN;
	TIM4->CR1 |= TIM_CR1_CEN;
	TIM1->EGR |= TIM_EGR_UG;
	TIM2->EGR |= TIM_EGR_UG;
	TIM3->EGR |= TIM_EGR_UG;
	TIM4->EGR |= TIM_EGR_UG;
}

HDPWM::~HDPWM()
{
	
}

void HDPWM::Enable(U8 index)
{
	Timer[index]->CCER |= 1<<(index%4*4);
}

void HDPWM::Disable(U8 index)
{
	Timer[index]->CCER &= ~1<<(index%4*4);
}

void HDPWM::SetDuty(U8 index,U16 duty)
{
	switch(index % 0x04)
	{
		case 0:
			Timer[index]->CCR1 = (U32)Timer[index]->ARR*duty/10000;
		  break;
		
		case 1:
			Timer[index]->CCR2 = (U32)Timer[index]->ARR*duty/10000;
		  break;
		
		case 2:
			Timer[index]->CCR3 = (U32)Timer[index]->ARR*duty/10000;
		  break;
		
		case 3:
			Timer[index]->CCR4 = (U32)Timer[index]->ARR*duty/10000;
		  break;
		
		default:break;
	}
	Timer[index]->EGR |= TIM_EGR_UG;
}



void HDPWM::SetFrequency(U8 index,U16 frequency)
{
	Timer[index]->ARR=(U16)(2000000/frequency);
	Timer[index]->EGR |= TIM_EGR_UG;
}

void HDPWM::SetPolarity(U8 index,BOOL Polarity)
{
	switch(index % 0x04)
	{
		case 0:
			__SFR_IO_BIT(((int)Timer[index]+VALUE_OFFSET_IN_STRUCT(TIM_TypeDef,CCER)),1) = Polarity;
		  break;
		
		case 1:
			__SFR_IO_BIT(((int)Timer[index]+VALUE_OFFSET_IN_STRUCT(TIM_TypeDef,CCER)),5) = Polarity;
		  break;
		
		case 2:
			__SFR_IO_BIT(((int)Timer[index]+VALUE_OFFSET_IN_STRUCT(TIM_TypeDef,CCER)),9) = Polarity;
		  break;
		
		case 3:
			__SFR_IO_BIT(((int)Timer[index]+VALUE_OFFSET_IN_STRUCT(TIM_TypeDef,CCER)),13) = Polarity;
		  break;
		
		default:break;
	}
	Timer[index]->EGR |= TIM_EGR_UG;
}

#ifndef __HARDWARE_PWM_H__
#define __HARDWARE_PWM_H__

extern "C" {	 
	#include <string.h> 
	#include "delay.h"
	#include "typedef.h"
	#include "stm32f10x.h"	 
}											

#define TIMER1_CLK  F_APB2
#define TIMER2_CLK (F_APB1*2)
#define TIMER3_CLK (F_APB1*2)
#define TIMER4_CLK (F_APB1*2)


class HDPWM {
	private:
	  TIM_TypeDef *Timer[16];
	public:
		 HDPWM();
    ~HDPWM();
	  void Initial(BOOL Polarity = TRUE, U16 frequency = 50,U16 duty = 500);
	  void Enable(U8 index);
	  void Disable(U8 index);
	  void SetDuty(U8 index,U16 duty);
	  void SetFrequency(U8 index,U16 frequency);
	  void SetPolarity(U8 index,BOOL Polarity);
};

#endif


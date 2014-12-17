#ifndef __PWM_TOP_H__
#define __PWM_TOP_H__

#include "pwm.h"
#include "hardware_pwm.h"

extern "C"  {
  #include "typedef.h"
	#include "pincfg.h"
}    

extern HDPWM hdPwm;
extern PWM pwm;

extern void (*PwmEnable[27])(void);
extern void (*PwmDisable[27])(void);
extern void (*PwmSetFrequency[27])(U16);
extern void (*PwmSetDuty[27])(U16);
extern void (*PwmSetPolarity[27])(BOOL);

extern void Pwm0PinCtrl(U8);
extern void Pwm1PinCtrl(U8);
extern void Pwm5PinCtrl(U8);
extern void Pwm6PinCtrl(U8);
extern void Pwm12PinCtrl(U8);
extern void Pwm13PinCtrl(U8);
extern void Pwm14PinCtrl(U8);
extern void Pwm15PinCtrl(U8);
extern void Pwm16PinCtrl(U8);
extern void Pwm21PinCtrl(U8);
extern void Pwm26PinCtrl(U8);


#endif

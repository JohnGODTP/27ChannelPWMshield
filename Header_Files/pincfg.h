#ifndef __PIN_CFG_H__
#define __PIN_CFG_H__


#include "gpio.h"

#define USE_HARDWARE_PWM 1


#ifdef USE_HARDWARE_PWM
  #define _Pwm0PinInitial() _GpioInitialAsGPPOutput(B,H,14)
	#define _Pwm1PinInitial() _GpioInitialAsGPPOutput(B,H,15)
	#define _Pwm2PinInitial() _GpioInitialAsAFPPOutput(B,L,1)////Hardware PWM
	#define _Pwm3PinInitial() _GpioInitialAsAFPPOutput(B,L,0)////Hardware PWM
	#define _Pwm4PinInitial() _GpioInitialAsAFPPOutput(A,L,7)////Hardware PWM
	#define _Pwm5PinInitial() _GpioInitialAsGPPOutput(A,L,4)
	#define _Pwm6PinInitial() _GpioInitialAsGPPOutput(A,L,5)
	#define _Pwm7PinInitial() _GpioInitialAsAFPPOutput(A,L,6)////Hardware PWM

	#define _Pwm8PinInitial() _GpioInitialAsAFPPOutput(A,L,0)////Hardware PWM
	#define _Pwm9PinInitial() _GpioInitialAsAFPPOutput(A,L,1)////Hardware PWM
	#define _Pwm10PinInitial() _GpioInitialAsAFPPOutput(A,L,3)////Hardware PWM
	#define _Pwm11PinInitial() _GpioInitialAsAFPPOutput(A,L,2)////Hardware PWM
	#define _Pwm12PinInitial() _GpioInitialAsGPPOutput(C,H,13)
	#define _Pwm13PinInitial() _GpioInitialAsGPPOutput(C,H,14)
	#define _Pwm14PinInitial() _GpioInitialAsGPPOutput(C,H,15)
	#define _Pwm15PinInitial() _GpioInitialAsGPPOutput(B,H,13)

	#define _Pwm16PinInitial() _GpioInitialAsGPPOutput(A,H,12)
	#define _Pwm17PinInitial() _GpioInitialAsAFPPOutput(A,H,11)////Hardware PWM
	#define _Pwm18PinInitial() _GpioInitialAsAFPPOutput(A,H,10)////Hardware PWM
	#define _Pwm19PinInitial() _GpioInitialAsAFPPOutput(A,H,9)////Hardware PWM

	#define _Pwm20PinInitial() _GpioInitialAsAFPPOutput(A,H,8)////Hardware PWM
	#define _Pwm21PinInitial() _GpioInitialAsGPPOutput(B,H,12)
	#define _Pwm22PinInitial() _GpioInitialAsAFPPOutput(B,H,8)////Hardware PWM
	#define _Pwm23PinInitial() _GpioInitialAsAFPPOutput(B,L,7)////Hardware PWM

	#define _Pwm24PinInitial() _GpioInitialAsAFPPOutput(B,H,9)////Hardware PWM
	#define _Pwm25PinInitial() _GpioInitialAsAFPPOutput(B,L,6)////Hardware PWM
	#define _Pwm26PinInitial() _GpioInitialAsGPPOutput(B,L,2)
#else
	#define _Pwm0PinInitial() _GpioInitialAsGPPOutput(A,L,0)
	#define _Pwm1PinInitial() _GpioInitialAsGPPOutput(A,L,1)
	#define _Pwm2PinInitial() _GpioInitialAsGPPOutput(A,L,2)
	#define _Pwm3PinInitial() _GpioInitialAsGPPOutput(A,L,3)
	#define _Pwm4PinInitial() _GpioInitialAsGPPOutput(A,L,4)
	#define _Pwm5PinInitial() _GpioInitialAsGPPOutput(A,L,5)
	#define _Pwm6PinInitial() _GpioInitialAsGPPOutput(A,L,6)
	#define _Pwm7PinInitial() _GpioInitialAsGPPOutput(A,L,7)

	#define _Pwm8PinInitial() _GpioInitialAsGPPOutput(A,H,8)
	#define _Pwm9PinInitial() _GpioInitialAsGPPOutput(A,H,9)
	#define _Pwm10PinInitial() _GpioInitialAsGPPOutput(A,H,10)
	#define _Pwm11PinInitial() _GpioInitialAsGPPOutput(A,H,11)
	#define _Pwm12PinInitial() _GpioInitialAsGPPOutput(A,H,12)
	#define _Pwm13PinInitial() _GpioInitialAsGPPOutput(A,H,15)
	#define _Pwm14PinInitial() _GpioInitialAsGPPOutput(B,L,0)
	#define _Pwm15PinInitial() _GpioInitialAsGPPOutput(B,L,1)

	#define _Pwm16PinInitial() _GpioInitialAsGPPOutput(B,L,2)
	#define _Pwm17PinInitial() _GpioInitialAsGPPOutput(B,L,3)
	#define _Pwm18PinInitial() _GpioInitialAsGPPOutput(B,L,4)
	#define _Pwm19PinInitial() _GpioInitialAsGPPOutput(B,L,5)

	#define _Pwm20PinInitial() _GpioInitialAsGPPOutput(B,H,8)
	#define _Pwm21PinInitial() _GpioInitialAsGPPOutput(B,H,9)
	#define _Pwm22PinInitial() _GpioInitialAsGPPOutput(B,H,10)
	#define _Pwm23PinInitial() _GpioInitialAsGPPOutput(B,H,11)

	#define _Pwm24PinInitial() _GpioInitialAsGPPOutput(C,H,13)
	#define _Pwm25PinInitial() _GpioInitialAsGPPOutput(C,H,14)
	#define _Pwm26PinInitial() _GpioInitialAsGPPOutput(C,H,15)
#endif


#define _Pwm0PinSet() _GpioSet(B,14)
#define _Pwm0PinClr() _GpioClr(B,14)
#define _Pwm0PinReversal() _GpioReversal(B,14)

#define _Pwm1PinSet() _GpioSet(B,15)
#define _Pwm1PinClr() _GpioClr(B,15)
#define _Pwm1PinReversal() _GpioReversal(B,15)

#define _Pwm2PinSet() _GpioSet(B,1)
#define _Pwm2PinClr() _GpioClr(B,1)
#define _Pwm2PinReversal() _GpioReversal(B,1)

#define _Pwm3PinSet() _GpioSet(B,0)
#define _Pwm3PinClr() _GpioClr(B,0)
#define _Pwm3PinReversal() _GpioReversal(B,0)

#define _Pwm4PinSet() _GpioSet(A,7)
#define _Pwm4PinClr() _GpioClr(A,7)
#define _Pwm4PinReversal() _GpioReversal(A,7)

#define _Pwm5PinSet() _GpioSet(A,4)
#define _Pwm5PinClr() _GpioClr(A,4)
#define _Pwm5PinReversal() _GpioReversal(A,4)

#define _Pwm6PinSet() _GpioSet(A,5)
#define _Pwm6PinClr() _GpioClr(A,5)
#define _Pwm6PinReversal() _GpioReversal(A,5)

#define _Pwm7PinSet() _GpioSet(A,6)
#define _Pwm7PinClr() _GpioClr(A,6)
#define _Pwm7PinReversal() _GpioReversal(A,6)

#define _Pwm8PinSet() _GpioSet(A,0)
#define _Pwm8PinClr() _GpioClr(A,0)
#define _Pwm8PinReversal() _GpioReversal(A,0)

#define _Pwm9PinSet() _GpioSet(A,1)
#define _Pwm9PinClr() _GpioClr(A,1)
#define _Pwm9PinReversal() _GpioReversal(A,1)

#define _Pwm10PinSet() _GpioSet(A,3)
#define _Pwm10PinClr() _GpioClr(A,3)
#define _Pwm10PinReversal() _GpioReversal(A,3)

#define _Pwm11PinSet() _GpioSet(A,2)
#define _Pwm11PinClr() _GpioClr(A,3)
#define _Pwm11PinReversal() _GpioReversal(A,3)

#define _Pwm12PinSet() _GpioSet(C,13)
#define _Pwm12PinClr() _GpioClr(C,13)
#define _Pwm12PinReversal() _GpioReversal(C,13)

#define _Pwm13PinSet() _GpioSet(C,14)
#define _Pwm13PinClr() _GpioClr(C,14)
#define _Pwm13PinReversal() _GpioReversal(C,14)

#define _Pwm14PinSet() _GpioSet(C,15)
#define _Pwm14PinClr() _GpioClr(C,15)
#define _Pwm14PinReversal() _GpioReversal(C,15)

#define _Pwm15PinSet() _GpioSet(B,13)
#define _Pwm15PinClr() _GpioClr(B,13)
#define _Pwm15PinReversal() _GpioReversal(B,13)

#define _Pwm16PinSet() _GpioSet(A,12)
#define _Pwm16PinClr() _GpioClr(A,12)
#define _Pwm16PinReversal() _GpioReversal(A,12)

#define _Pwm17PinSet() _GpioSet(A,11)
#define _Pwm17PinClr() _GpioClr(A,11)
#define _Pwm17PinReversal() _GpioReversal(A,11)

#define _Pwm18PinSet() _GpioSet(A,10)
#define _Pwm18PinClr() _GpioClr(A,10)
#define _Pwm18PinReversal() _GpioReversal(A,10)

#define _Pwm19PinSet() _GpioSet(A,9)
#define _Pwm19PinClr() _GpioClr(A,9)
#define _Pwm19PinReversal() _GpioReversal(A,9)

#define _Pwm20PinSet() _GpioSet(A,8)
#define _Pwm20PinClr() _GpioClr(A,8)
#define _Pwm20PinReversal() _GpioReversal(A,8)

#define _Pwm21PinSet() _GpioSet(B,12)
#define _Pwm21PinClr() _GpioClr(B,12)
#define _Pwm21PinReversal() _GpioReversal(B,12)

#define _Pwm22PinSet() _GpioSet(B,8)
#define _Pwm22PinClr() _GpioClr(B,8)
#define _Pwm22PinReversal() _GpioReversal(B,10)

#define _Pwm23PinSet() _GpioSet(B,7)
#define _Pwm23PinClr() _GpioClr(B,7)
#define _Pwm23PinReversal() _GpioReversal(B,7)

#define _Pwm24PinSet() _GpioSet(B,15)
#define _Pwm24PinClr() _GpioClr(B,15)
#define _Pwm24PinReversal() _GpioReversal(B,15)

#define _Pwm25PinSet() _GpioSet(B,12)
#define _Pwm25PinClr() _GpioClr(B,12)
#define _Pwm25PinReversal() _GpioReversal(B,12)

#define _Pwm26PinSet() _GpioSet(B,2)
#define _Pwm26PinClr() _GpioClr(B,2)
#define _Pwm26PinReversal() _GpioReversal(B,2)

#define _CsPinInitial() _GpioInitialAsPInput(A,H,15)
#define _SckPinInitial() _GpioInitialAsPInput(B,L,3)
#define _MisoPinInitial() _GpioInitialAsAFPPOutput(B,L,4)
#define _MosiPinInitial() _GpioInitialAsPInput(B,L,5)


#define _SclPinInitial() _GpioInitialAsAFODOutput(B,H,10)
#define _SdaPinInitial() _GpioInitialAsAFODOutput(B,H,11)

#define _TxPinInitial() _GpioInitialAsAFODOutput(B,H,10)
#define _RxPinInitial() _GpioInitialAsAFODOutput(B,H,11)

#endif


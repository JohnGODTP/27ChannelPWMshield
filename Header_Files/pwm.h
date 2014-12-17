#ifndef __PWM_H__
#define __PWM_H__

extern "C"{
#include"typedef.h"
}
#define MAX_CHANNEL 11

class PWM {
	
	private:
		BOOL En[MAX_CHANNEL];
	  U16 Top[MAX_CHANNEL];
	  U16 Arr[MAX_CHANNEL];
	  U16 Count[MAX_CHANNEL];
	  BOOL Polarity[MAX_CHANNEL];
	  void (*PinOut[MAX_CHANNEL])(U8);
	  
	public:
		PWM(void *PinOut = NULL, BOOL Polarity = TRUE, U16 frequency = 50,U16 duty = 500);
    ~PWM();
	  void Reset(U8 index);
	  void Enable(U8 index);
	  void Disable(U8 index);
	  void SetDuty(U8 index,U16 duty);
	  void SetFrequency(U8 index,U16 frequency);
	  void SetPolarity(U8 index,BOOL Polarity);
	  void SetOutPutSignal(U8 index,void (*PinOut)(U8));  
	 
	  void RunningTask(U32 numClk);
};


#endif



#include "pwm.h"


PWM ::PWM(void *PinOut, BOOL Polarity, U16 frequency,U16 duty)
{
	U8 index;
	U16 top;
	U16 arr;

	top = (U32)200000/frequency; //source clk 200KHZ
	arr = (U32)top*duty/10000;
	for(index = 0;index <MAX_CHANNEL;index ++)
	{
		En[index] = FALSE;
		Count[index] = 0x0000;
		this->Top[index] = top;
		this->Arr[index] = arr;
		this->Polarity[index] = Polarity; 
		this->PinOut[index] = ((void (**)(U8))PinOut)[index];
		this->PinOut[index](Polarity);
	}
}

PWM ::~PWM()
{
	
	
	
}


void PWM ::Reset(U8 index)
{
	Count[index] = 0x0000;
	PinOut[index](Polarity[index]);
}

void PWM ::Enable(U8 index)
{
	En[index] = TRUE;
	//PinOut[index](Polarity[index]);
}


void PWM ::Disable(U8 index)
{
	En[index] = FALSE;
	Reset(index);
}
	 
void PWM::SetDuty(U8 index,U16 duty)
{
	U16 arr;

	arr = (U16)((U32)Top[index]*duty/10000);
	Arr[index] = arr;
}


void PWM::SetFrequency(U8 index,U16 frequency)
{
	U16 top;

	top = (U32)200000/frequency; //source clk 200KHZ
  Top[index] = top;
}


void PWM ::SetPolarity(U8 index,BOOL Polarity)
{
	this->Polarity[index] = Polarity;
	Reset(index);
}


void PWM ::SetOutPutSignal(U8 index,void (*PinOut)(U8))
{
	Reset(index);
	this->PinOut[index] = PinOut;
}

void PWM ::RunningTask(U32 numClk)
{
	U8 index;
	
	for(index = 0;index <MAX_CHANNEL;index ++)
	{
		if(!En[index])continue;
		if(Count[index] >= Arr[index])
		{
			Count[index] += numClk;
		  if(Count[index] >= Top[index])
		  {
			  PinOut[index](0x02);
			  Count[index] = 0x0000;
		  }
		}
		else 
		{
			Count[index] += numClk;
			if(Count[index] >= Arr[index])PinOut[index](0x02);
		}
  }
}





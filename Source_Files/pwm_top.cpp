#include "pwm_top.h"

HDPWM hdPwm;

void (*PwmPinCtrl[MAX_CHANNEL])(U8)={
	Pwm0PinCtrl,
	Pwm1PinCtrl,
	Pwm5PinCtrl,
	Pwm6PinCtrl,
	Pwm12PinCtrl,
	Pwm13PinCtrl,
	Pwm14PinCtrl,
	Pwm15PinCtrl,
	Pwm16PinCtrl,
	Pwm21PinCtrl,
	Pwm26PinCtrl
};

PWM pwm(PwmPinCtrl,TRUE,50,500);

void PwmEnable0(void)
{
	pwm.Enable(0);
}

void PwmEnable1(void)
{
	pwm.Enable(1);
}

void PwmEnable2(void)
{
	hdPwm.Enable(11);
}

void PwmEnable3(void)
{
	hdPwm.Enable(10);
}

void PwmEnable4(void)
{
	hdPwm.Enable(9);
}

void PwmEnable5(void)
{
	pwm.Enable(2);
}

void PwmEnable6(void)
{
	pwm.Enable(3);
}

void PwmEnable7(void)
{
	hdPwm.Enable(8);
}

void PwmEnable8(void)
{
	hdPwm.Enable(4);
}

void PwmEnable9(void)
{
	hdPwm.Enable(5);
}

void PwmEnable10(void)
{
	hdPwm.Enable(7);
}

void PwmEnable11(void)
{
  hdPwm.Enable(6);
}

void PwmEnable12(void)
{
	pwm.Enable(4);
}

void PwmEnable13(void)
{
	pwm.Enable(5);
}

	
void PwmEnable14(void)
{
	pwm.Enable(6);
}

void PwmEnable15(void)
{
	pwm.Enable(7);
}

void PwmEnable16(void)
{
	pwm.Enable(8);
}

void PwmEnable17(void)
{
	hdPwm.Enable(3);
}
void PwmEnable18(void)
{
	hdPwm.Enable(2);
}

void PwmEnable19(void)
{
	hdPwm.Enable(1);
}

void PwmEnable20(void)
{
	hdPwm.Enable(0);
}

void PwmEnable21(void)
{
	pwm.Enable(9);
}

void PwmEnable22(void)
{
	hdPwm.Enable(14);
}

void PwmEnable23(void)
{
	hdPwm.Enable(13);
}

void PwmEnable24(void)
{
	hdPwm.Enable(15);
}

void PwmEnable25(void)
{
	hdPwm.Enable(12);
}

void PwmEnable26(void)
{
	pwm.Enable(10);
}


void (*PwmEnable[27])(void)={
  PwmEnable0,
	PwmEnable1,
	PwmEnable2,
	PwmEnable3,
	PwmEnable4,
	PwmEnable5,
	PwmEnable6,
	PwmEnable7,
	PwmEnable8,
	PwmEnable9,
	PwmEnable10,
	PwmEnable11,
	PwmEnable12,
	PwmEnable13,
	PwmEnable14,
	PwmEnable15,
	PwmEnable16,
	PwmEnable17,
	PwmEnable18,
	PwmEnable19,
	PwmEnable20,
	PwmEnable21,
	PwmEnable22,
	PwmEnable23,
	PwmEnable24,
	PwmEnable25,
	PwmEnable26
};

void PwmDisable0(void)
{
	pwm.Disable(0);
}

void PwmDisable1(void)
{
	pwm.Disable(1);
}

void PwmDisable2(void)
{
	hdPwm.Disable(11);
}

void PwmDisable3(void)
{
	hdPwm.Disable(10);
}

void PwmDisable4(void)
{
	hdPwm.Disable(9);
}

void PwmDisable5(void)
{
	pwm.Disable(2);
}

void PwmDisable6(void)
{
	pwm.Disable(3);
}

void PwmDisable7(void)
{
	hdPwm.Disable(8);
}

void PwmDisable8(void)
{
	hdPwm.Disable(4);
}

void PwmDisable9(void)
{
	hdPwm.Disable(5);
}

void PwmDisable10(void)
{
	hdPwm.Disable(7);
}

void PwmDisable11(void)
{
  hdPwm.Disable(6);
}

void PwmDisable12(void)
{
	pwm.Disable(4);
}

void PwmDisable13(void)
{
	pwm.Disable(5);
}

	
void PwmDisable14(void)
{
	pwm.Disable(6);
}

void PwmDisable15(void)
{
	pwm.Disable(7);
}

void PwmDisable16(void)
{
	pwm.Disable(8);
}

void PwmDisable17(void)
{
	hdPwm.Disable(3);
}
void PwmDisable18(void)
{
	hdPwm.Disable(2);
}

void PwmDisable19(void)
{
	hdPwm.Disable(1);
}

void PwmDisable20(void)
{
	hdPwm.Disable(0);
}

void PwmDisable21(void)
{
	pwm.Disable(9);
}

void PwmDisable22(void)
{
	hdPwm.Disable(14);
}

void PwmDisable23(void)
{
	hdPwm.Disable(13);
}

void PwmDisable24(void)
{
	hdPwm.Disable(15);
}

void PwmDisable25(void)
{
	hdPwm.Disable(12);
}

void PwmDisable26(void)
{
	pwm.Disable(10);
}

void (*PwmDisable[27])(void)={
  PwmDisable0,
	PwmDisable1,
	PwmDisable2,
	PwmDisable3,
	PwmDisable4,
	PwmDisable5,
	PwmDisable6,
	PwmDisable7,
	PwmDisable8,
	PwmDisable9,
	PwmDisable10,
	PwmDisable11,
	PwmDisable12,
	PwmDisable13,
	PwmDisable14,
	PwmDisable15,
	PwmDisable16,
	PwmDisable17,
	PwmDisable18,
	PwmDisable19,
	PwmDisable20,
	PwmDisable21,
	PwmDisable22,
	PwmDisable23,
	PwmDisable24,
	PwmDisable25,
	PwmDisable26
};

void PwmSetFrequency0(U16 frequency)
{
	pwm.SetFrequency(0,frequency);
}

void PwmSetFrequency1(U16 frequency)
{
	pwm.SetFrequency(1,frequency);
}

void PwmSetFrequency2(U16 frequency)
{
	hdPwm.SetFrequency(11,frequency);
}

void PwmSetFrequency3(U16 frequency)
{
	hdPwm.SetFrequency(10,frequency);
}

void PwmSetFrequency4(U16 frequency)
{
	hdPwm.SetFrequency(9,frequency);
}

void PwmSetFrequency5(U16 frequency)
{
	pwm.SetFrequency(2,frequency);
}

void PwmSetFrequency6(U16 frequency)
{
	pwm.SetFrequency(3,frequency);
}

void PwmSetFrequency7(U16 frequency)
{
	hdPwm.SetFrequency(8,frequency);
}

void PwmSetFrequency8(U16 frequency)
{
	hdPwm.SetFrequency(4,frequency);
}

void PwmSetFrequency9(U16 frequency)
{
	hdPwm.SetFrequency(5,frequency);
}

void PwmSetFrequency10(U16 frequency)
{
	hdPwm.SetFrequency(7,frequency);
}

void PwmSetFrequency11(U16 frequency)
{
  hdPwm.SetFrequency(6,frequency);
}

void PwmSetFrequency12(U16 frequency)
{
	pwm.SetFrequency(4,frequency);
}

void PwmSetFrequency13(U16 frequency)
{
	pwm.SetFrequency(5,frequency);
}

	
void PwmSetFrequency14(U16 frequency)
{
	pwm.SetFrequency(6,frequency);
}

void PwmSetFrequency15(U16 frequency)
{
	pwm.SetFrequency(7,frequency);
}

void PwmSetFrequency16(U16 frequency)
{
	pwm.SetFrequency(8,frequency);
}

void PwmSetFrequency17(U16 frequency)
{
	hdPwm.SetFrequency(3,frequency);
}
void PwmSetFrequency18(U16 frequency)
{
	hdPwm.SetFrequency(2,frequency);
}

void PwmSetFrequency19(U16 frequency)
{
	hdPwm.SetFrequency(1,frequency);
}

void PwmSetFrequency20(U16 frequency)
{
	hdPwm.SetFrequency(0,frequency);
}

void PwmSetFrequency21(U16 frequency)
{
	pwm.SetFrequency(9,frequency);
}

void PwmSetFrequency22(U16 frequency)
{
	hdPwm.SetFrequency(14,frequency);
}

void PwmSetFrequency23(U16 frequency)
{
	hdPwm.SetFrequency(13,frequency);
}

void PwmSetFrequency24(U16 frequency)
{
	hdPwm.SetFrequency(15,frequency);
}

void PwmSetFrequency25(U16 frequency)
{
	hdPwm.SetFrequency(12,frequency);
}

void PwmSetFrequency26(U16 frequency)
{
	pwm.SetFrequency(10,frequency);
}




void (*PwmSetFrequency[27])(U16)={
	PwmSetFrequency0,
	PwmSetFrequency1,
	PwmSetFrequency2,
	PwmSetFrequency3,
	PwmSetFrequency4,
	PwmSetFrequency5,
	PwmSetFrequency6,
	PwmSetFrequency7,
	PwmSetFrequency8,
	PwmSetFrequency9,
	PwmSetFrequency10,
	PwmSetFrequency11,
	PwmSetFrequency12,
	PwmSetFrequency13,
	PwmSetFrequency14,
	PwmSetFrequency15,
	PwmSetFrequency16,
	PwmSetFrequency17,
	PwmSetFrequency18,
	PwmSetFrequency19,
	PwmSetFrequency20,
	PwmSetFrequency21,
	PwmSetFrequency22,
	PwmSetFrequency23,
	PwmSetFrequency24,
	PwmSetFrequency25,
	PwmSetFrequency26
};



void PwmSetDuty0(U16 Duty)
{
	pwm.SetDuty(0,Duty);
}

void PwmSetDuty1(U16 Duty)
{
	pwm.SetDuty(1,Duty);
}

void PwmSetDuty2(U16 Duty)
{
	hdPwm.SetDuty(11,Duty);
}

void PwmSetDuty3(U16 Duty)
{
	hdPwm.SetDuty(10,Duty);
}

void PwmSetDuty4(U16 Duty)
{
	hdPwm.SetDuty(9,Duty);
}

void PwmSetDuty5(U16 Duty)
{
	pwm.SetDuty(2,Duty);
}

void PwmSetDuty6(U16 Duty)
{
	pwm.SetDuty(3,Duty);
}

void PwmSetDuty7(U16 Duty)
{
	hdPwm.SetDuty(8,Duty);
}

void PwmSetDuty8(U16 Duty)
{
	hdPwm.SetDuty(4,Duty);
}

void PwmSetDuty9(U16 Duty)
{
	hdPwm.SetDuty(5,Duty);
}

void PwmSetDuty10(U16 Duty)
{
	hdPwm.SetDuty(7,Duty);
}

void PwmSetDuty11(U16 Duty)
{
  hdPwm.SetDuty(6,Duty);
}

void PwmSetDuty12(U16 Duty)
{
	pwm.SetDuty(4,Duty);
}

void PwmSetDuty13(U16 Duty)
{
	pwm.SetDuty(5,Duty);
}

	
void PwmSetDuty14(U16 Duty)
{
	pwm.SetDuty(6,Duty);
}

void PwmSetDuty15(U16 Duty)
{
	pwm.SetDuty(7,Duty);
}

void PwmSetDuty16(U16 Duty)
{
	pwm.SetDuty(8,Duty);
}

void PwmSetDuty17(U16 Duty)
{
	hdPwm.SetDuty(3,Duty);
}
void PwmSetDuty18(U16 Duty)
{
	hdPwm.SetDuty(2,Duty);
}

void PwmSetDuty19(U16 Duty)
{
	hdPwm.SetDuty(1,Duty);
}

void PwmSetDuty20(U16 Duty)
{
	hdPwm.SetDuty(0,Duty);
}

void PwmSetDuty21(U16 Duty)
{
	pwm.SetDuty(9,Duty);
}

void PwmSetDuty22(U16 Duty)
{
	hdPwm.SetDuty(14,Duty);
}

void PwmSetDuty23(U16 Duty)
{
	hdPwm.SetDuty(13,Duty);
}

void PwmSetDuty24(U16 Duty)
{
	hdPwm.SetDuty(15,Duty);
}

void PwmSetDuty25(U16 Duty)
{
	hdPwm.SetDuty(12,Duty);
}

void PwmSetDuty26(U16 Duty)
{
	pwm.SetDuty(10,Duty);
}


void (*PwmSetDuty[27])(U16)={
	PwmSetDuty0,
	PwmSetDuty1,
	PwmSetDuty2,
	PwmSetDuty3,
	PwmSetDuty4,
	PwmSetDuty5,
	PwmSetDuty6,
	PwmSetDuty7,
	PwmSetDuty8,
	PwmSetDuty9,
	PwmSetDuty10,
	PwmSetDuty11,
	PwmSetDuty12,
	PwmSetDuty13,
	PwmSetDuty14,
	PwmSetDuty15,
	PwmSetDuty16,
	PwmSetDuty17,
	PwmSetDuty18,
	PwmSetDuty19,
	PwmSetDuty20,
	PwmSetDuty21,
	PwmSetDuty22,
	PwmSetDuty23,
	PwmSetDuty24,
	PwmSetDuty25,
	PwmSetDuty26
};



void PwmSetPolarity0(BOOL Polarity)
{
	pwm.SetPolarity(0,Polarity);
}

void PwmSetPolarity1(BOOL Polarity)
{
	pwm.SetPolarity(1,Polarity);
}

void PwmSetPolarity2(BOOL Polarity)
{
	hdPwm.SetPolarity(11,Polarity);
}

void PwmSetPolarity3(BOOL Polarity)
{
	hdPwm.SetPolarity(10,Polarity);
}

void PwmSetPolarity4(BOOL Polarity)
{
	hdPwm.SetPolarity(9,Polarity);
}

void PwmSetPolarity5(BOOL Polarity)
{
	pwm.SetPolarity(2,Polarity);
}

void PwmSetPolarity6(BOOL Polarity)
{
	pwm.SetPolarity(3,Polarity);
}

void PwmSetPolarity7(BOOL Polarity)
{
	hdPwm.SetPolarity(8,Polarity);
}

void PwmSetPolarity8(BOOL Polarity)
{
	hdPwm.SetPolarity(4,Polarity);
}

void PwmSetPolarity9(BOOL Polarity)
{
	hdPwm.SetPolarity(5,Polarity);
}

void PwmSetPolarity10(BOOL Polarity)
{
	hdPwm.SetPolarity(7,Polarity);
}

void PwmSetPolarity11(BOOL Polarity)
{
  hdPwm.SetPolarity(6,Polarity);
}

void PwmSetPolarity12(BOOL Polarity)
{
	pwm.SetPolarity(4,Polarity);
}

void PwmSetPolarity13(BOOL Polarity)
{
	pwm.SetPolarity(5,Polarity);
}

	
void PwmSetPolarity14(BOOL Polarity)
{
	pwm.SetPolarity(6,Polarity);
}

void PwmSetPolarity15(BOOL Polarity)
{
	pwm.SetPolarity(7,Polarity);
}

void PwmSetPolarity16(BOOL Polarity)
{
	pwm.SetPolarity(8,Polarity);
}

void PwmSetPolarity17(BOOL Polarity)
{
	hdPwm.SetPolarity(3,Polarity);
}
void PwmSetPolarity18(BOOL Polarity)
{
	hdPwm.SetPolarity(2,Polarity);
}

void PwmSetPolarity19(BOOL Polarity)
{
	hdPwm.SetPolarity(1,Polarity);
}

void PwmSetPolarity20(BOOL Polarity)
{
	hdPwm.SetPolarity(0,Polarity);
}

void PwmSetPolarity21(BOOL Polarity)
{
	pwm.SetPolarity(9,Polarity);
}

void PwmSetPolarity22(BOOL Polarity)
{
	hdPwm.SetPolarity(14,Polarity);
}

void PwmSetPolarity23(BOOL Polarity)
{
	hdPwm.SetPolarity(13,Polarity);
}

void PwmSetPolarity24(BOOL Polarity)
{
	hdPwm.SetPolarity(15,Polarity);
}

void PwmSetPolarity25(BOOL Polarity)
{
	hdPwm.SetPolarity(12,Polarity);
}

void PwmSetPolarity26(BOOL Polarity)
{
	pwm.SetPolarity(10,Polarity);
}

void (*PwmSetPolarity[27])(BOOL)={
	PwmSetPolarity0,
	PwmSetPolarity1,
	PwmSetPolarity2,
	PwmSetPolarity3,
	PwmSetPolarity4,
	PwmSetPolarity5,
	PwmSetPolarity6,
	PwmSetPolarity7,
	PwmSetPolarity8,
	PwmSetPolarity9,
	PwmSetPolarity10,
	PwmSetPolarity11,
	PwmSetPolarity12,
	PwmSetPolarity13,
	PwmSetPolarity14,
	PwmSetPolarity15,
	PwmSetPolarity16,
	PwmSetPolarity17,
	PwmSetPolarity18,
	PwmSetPolarity19,
	PwmSetPolarity20,
	PwmSetPolarity21,
	PwmSetPolarity22,
	PwmSetPolarity23,
	PwmSetPolarity24,
	PwmSetPolarity25,
	PwmSetPolarity26

};

	
void Pwm0PinCtrl(U8 value)
{
	if(value == 2)_Pwm0PinReversal();
	else if(value == 1)_Pwm0PinSet();
	else _Pwm0PinClr();
}

void Pwm1PinCtrl(U8 value)
{
	if(value == 2)_Pwm1PinReversal();
	else if(value == 1)_Pwm1PinSet();
	else _Pwm1PinClr();
}


void Pwm5PinCtrl(U8 value)
{
	if(value == 2)_Pwm5PinReversal();
	else if(value == 1)_Pwm5PinSet();
	else _Pwm5PinClr();
}

void Pwm6PinCtrl(U8 value)
{
	if(value == 2)_Pwm6PinReversal();
	else if(value == 1)_Pwm6PinSet();
	else _Pwm6PinClr();
}

void Pwm12PinCtrl(U8 value)
{
	if(value == 2)_Pwm12PinReversal();
	else if(value == 1)_Pwm12PinSet();
	else _Pwm12PinClr();
}

void Pwm13PinCtrl(U8 value)
{
	if(value == 2)_Pwm13PinReversal();
	else if(value == 1)_Pwm13PinSet();
	else _Pwm13PinClr();
}

void Pwm14PinCtrl(U8 value)
{
	if(value == 2)_Pwm14PinReversal();
	else if(value == 1)_Pwm14PinSet();
	else _Pwm14PinClr();
}

void Pwm15PinCtrl(U8 value)
{
	if(value == 2)_Pwm15PinReversal();
	else if(value == 1)_Pwm15PinSet();
	else _Pwm15PinClr();
}

void Pwm16PinCtrl(U8 value)
{
	if(value == 2)_Pwm16PinReversal();
	else if(value == 1)_Pwm16PinSet();
	else _Pwm16PinClr();
}



void Pwm21PinCtrl(U8 value)
{
	if(value == 2)_Pwm21PinReversal();
	else if(value == 1)_Pwm21PinSet();
	else _Pwm21PinClr();
}



void Pwm26PinCtrl(U8 value)
{
	if(value == 2)_Pwm26PinReversal();
	else if(value == 1)_Pwm26PinSet();
	else _Pwm26PinClr();
}







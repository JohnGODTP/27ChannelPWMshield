/***************************************************
This program was produced by the Keil uVision5

Project : Pwm
Version : 1.0
Date    : 2014/6/20
Author  : JingJing
Company : Linksprite
Comments: 

Chip type           : STM32F103C8T6
Program type        : Application
Clock frequency     : 72.0000 MHz
Memory model        : Small
******************************************************/

extern "C"  {
  #include <string.h> 
	#include "delay.h"
}                  

#include "spi.h"
#include "pwm_top.h"
#include "ring_buffer.h"


/*****************Message format*******************************
  index   Byte1  Byte2   Byte3    Byte4   Byte5      Byte6  
  mean    START   CMD    INDEX   VALUE_L  VALUE_H   CHECK_SUM
***************************************************************/
#define WORK_BUF_SIZE 128
#define UART_FIFO_SIZE 128


#define MSG_START  0x87
#define MSG_INDEX_START 0
#define MSG_INDEX_CMD   1
#define MSG_INDEX_INDEX 2
#define MSG_INDEX_VALUEL 3
#define MSG_INDEX_VALUEH 4
#define MSG_INDEX_CHKSUM 5
#define MSG_MAX_LENGTH  6
#define DEFAULT_TOP 256//860
#define DEFAULT_ARR (1)

#define CMD_SET_ON_OFF 0x01
#define CMD_SET_POLARITY 0x02
#define CMD_SET_FREQ 0x03
#define CMD_SET_DUTY 0x04

					
					
typedef enum _STATE_{
	MSG_IDLE = 0,
	MSG_BEGIN,
	MSG_RECEIVING,
	MSG_END,
	MSG_ERROR
}MessageState_t;


volatile char CmdBuffer[1024];

RingBuffer<U8> SpiFifo;

void Spi1ISR(void)
{
	U8 data;
	
	SpiFifo.Push(GetSpiData());
	while(SpiPoll(&data))SpiFifo.Push(data);
}




void RccCfg(void)
{
	//reset register value
	RCC->CR= 0x00000083;
	RCC->CFGR = 0x00000000;
	RCC->CIR = 0x009f0000;
	RCC->APB2RSTR = 0xFFFFFFFF;
	RCC->APB1RSTR = 0xFFFFFFFF;
	RCC->AHBENR = 0x00000014;
	RCC->APB2ENR = 0x00000000;
	RCC->APB1ENR = 0x00000000;
	RCC->BDCR = 0x01000000;	
	//enable HSE  enable Clock security system 
	RCC->CR |= (RCC_CR_HSEON | RCC_CR_CSSON);
	// Wait till HSE is ready
	while((RCC->CR & RCC_CR_HSERDY)==0){}
  // Enable Prefetch Buffer
  FLASH->ACR &= 0xFFFFFFE0;
  FLASH->ACR |= (FLASH_ACR_PRFTBE|FLASH_ACR_LATENCY_2);
	//8*9=72MHZ,HSE oscillator clock selected as PLL input clock,APB low-speed prescaler 2	
	RCC->CFGR |= (RCC_CFGR_PLLMULL9 | 
		            RCC_CFGR_PLLSRC | 
		            RCC_CFGR_PPRE2_DIV1 | 
		            RCC_CFGR_PPRE1_DIV2 |
		            RCC_CFGR_HPRE_DIV1);	
	//enable pll
	RCC->CR |= RCC_CR_PLLON;	
	// Wait PLL lock
	while((RCC->CR & RCC_CR_PLLRDY)==0){}	
  //clock switch
	RCC->CFGR |= RCC_CFGR_SW_PLL;
  //wait for switch
	while((RCC->CFGR & RCC_CFGR_SWS)!= RCC_CFGR_SWS_PLL){;}	
  //reset end		
  RCC->APB2RSTR = 0x00000000;
	RCC->APB1RSTR = 0x00000000;		
}

//alternate-function I/Os
void AfIoCfg(void)
{
	//reset register value
	RCC->APB2RSTR |= RCC_APB2RSTR_AFIORST;
	delay_us(10);
	RCC->APB2RSTR &= (~RCC_APB2RSTR_AFIORST);
  delay_us(10);
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN; //enable AFIO clk 
	delay_us(10);
  AFIO->MAPR = ((2<<24)|(1<<0));//disable jtag and remap spi1 (NSS/PA15, SCK/PB3, MISO/PB4, MOSI/PB5)
}

void GpioCfg(void)
{
	//reset register value
	RCC->APB2RSTR |= (RCC_APB2RSTR_IOPARST | RCC_APB2RSTR_IOPBRST | 
	                  RCC_APB2RSTR_IOPCRST | RCC_APB2RSTR_IOPDRST);
	delay_us(10);
	RCC->APB2RSTR &= (~(RCC_APB2RSTR_IOPARST | RCC_APB2RSTR_IOPBRST | 
	                  RCC_APB2RSTR_IOPCRST | RCC_APB2RSTR_IOPDRST));
	
	
	_Pwm0PinInitial();
	_Pwm1PinInitial();
	_Pwm2PinInitial();
	_Pwm3PinInitial();
	_Pwm4PinInitial();
	_Pwm5PinInitial();
	_Pwm6PinInitial();
	_Pwm7PinInitial();
	
	_Pwm8PinInitial();
	_Pwm9PinInitial();
	_Pwm10PinInitial();
	_Pwm11PinInitial();
	_Pwm12PinInitial();
	_Pwm13PinInitial();
	_Pwm14PinInitial();
	_Pwm15PinInitial();
	
	_Pwm16PinInitial();
	_Pwm17PinInitial();
	_Pwm18PinInitial();
	_Pwm19PinInitial();
	_Pwm20PinInitial();
	_Pwm21PinInitial();
	_Pwm22PinInitial();
	_Pwm23PinInitial();
	
	_Pwm24PinInitial();
	_Pwm25PinInitial();
	_Pwm26PinInitial();
}


int main(int argc,char**arg)
{
  U32 UartRxCnt;
	U8  Index;
	U32 tmpTcnt;
	U32 TcntHistory;
	U32 tmpInt0;
	U32 tmpInt1;
	U32 Count;
	U8  CheckSum ;
  U8  MSgCount;
  U32 CntForMsg;
  U8  Cmd[MSG_MAX_LENGTH];
  MessageState_t MessageState;
  
	RccCfg();
	AfIoCfg();
	GpioCfg();
	Index = 0x00;
	CntForMsg = 0x00000000;
  SpiFifo.SetBuffer((U8*)CmdBuffer,sizeof(CmdBuffer));
	memset((char*)Cmd,0,sizeof(Cmd));
  memset((char*)CmdBuffer,0,sizeof(CmdBuffer));
	SpiInitial(2, //2,4,8,16,32,64,128,256
						SLAVE,
						FMSB,
						CLK_START_EDGE_RISING,
						DATA_SET_AT_LEADING_EDGE,
						(void *)Spi1ISR);
	Count = 0;
	tmpInt0 = 0;
	tmpInt1 = 0;
  CheckSum = 0;
  MSgCount = 0;
  hdPwm.Initial();
  MessageState = MSG_IDLE;
	TcntHistory = TIM1->CNT;
  
	while(1)
	{
		tmpTcnt = TIM1->CNT;
    if(TcntHistory != tmpTcnt)
    {
      if(TcntHistory > tmpTcnt) tmpInt0 = tmpTcnt + TIM1->ARR - TcntHistory + tmpInt1;  
      else if(TcntHistory < tmpTcnt)tmpInt0 = tmpTcnt - TcntHistory + tmpInt1;
      tmpInt1 = tmpInt0%10;
      Count += tmpInt0/10;
      TcntHistory = tmpTcnt;
    }
		if(Count)
		{
			pwm.RunningTask(Count);
			Count = 0;
			if(MessageState == MSG_RECEIVING)
		  {
			  if(CntForMsg < 10000)CntForMsg ++;
		  }
		}
    
    switch(MessageState)
    {
      case MSG_IDLE:
        if(SpiFifo.Pop(&Cmd[0]))MessageState = MSG_BEGIN;
      break;
      
      case MSG_BEGIN:
        if(Cmd[0] == MSG_START)
        {
          MSgCount = 1;
          CheckSum = Cmd[0];
          MessageState = MSG_RECEIVING;
        }
        else 
        {
          SpiSlaveSynchronize();
          MessageState = MSG_IDLE;
        }
      break;
      
      case MSG_RECEIVING:
        if(SpiFifo.Pop(&Cmd[MSgCount]))
        {
          CheckSum += Cmd[MSgCount];
          if(++MSgCount == MSG_MAX_LENGTH)
          {
            if(0xff &(CheckSum - Cmd[MSgCount-1]*2))MessageState = MSG_ERROR;
            else MessageState = MSG_END;
          }
        }
      break;
      
      case MSG_END:
        Index = Cmd[MSG_INDEX_INDEX];
        switch(Cmd[MSG_INDEX_CMD])
				{
					case CMD_SET_ON_OFF://set on or off
						if(Cmd[MSG_INDEX_VALUEL] & 0x01)PwmEnable[Index]();
						else PwmDisable[Index]();
					  break;
					
					case CMD_SET_POLARITY://set Polarity
						PwmSetPolarity[Index](Cmd[MSG_INDEX_VALUEL] & 0x01);
					  break;
					
					case CMD_SET_FREQ://set frequency
						PwmSetFrequency[Index](*((U16*)&Cmd[MSG_INDEX_VALUEL]));
					  break;				
					
					case CMD_SET_DUTY://set duty
						PwmSetDuty[Index](*((U16*)&Cmd[MSG_INDEX_VALUEL]));
					  break;
					
					default:break;
				}
        MessageState = MSG_IDLE;
      break;
      
      case MSG_ERROR:
      default:
        SpiFifo.ReSet();
        SpiSlaveSynchronize();
        MessageState = MSG_IDLE;
      break;
    }
	}
	return 1;
}

#ifndef _MSCOMM_H_
#define _MSCOMM_H_


extern "C"{ 
	#include <stdlib.h>
	#include <string.h> 
	#include "gpio.h"
	#include "typedef.h"
	#include "stm32f10x.h"	
}

#include "ring_buffer.h"



#define USART_TXC_INTERRUPT_ENABLE



class CByteArray
{
private:
	 char *data;
   unsigned short length;
// Attributes
public:
   
// Operations
public:
		CByteArray();
		~CByteArray();
		void SetSize(unsigned short NewVale);
		void SetDataPoint(char *p);
		void SetAs(unsigned short index,char DA);
		unsigned short GetLength(void);
		char* GetDataPoint(void);
};

typedef CByteArray* LPCByteArray;
	 
class CMSComm 
{
private:
	unsigned short CMSComm_timeout,
								 CMSComm_CR1,
								 CMSComm_CR2,
								 CMSComm_CR3,
								 CMSComm_GTPR;
	
	RingBuffer<U8> FifoIn;
  RingBuffer<U8> FifoOut;					  
  unsigned char CMSComm_port;
  
  BOOL wait_to_send;	
	long CMSComm_bud;
// Attributes
public:
// Operations
				
public:
		CMSComm();
		~CMSComm();
		void SetInBuffer(LPCByteArray nNewValue);
		CByteArray GetInBuffer();
		void SetOutBuffer(LPCByteArray nNewValue);
		CByteArray GetOutBuffer();
		void SetCommPort(char NewValue); //COM1
		char GetCommPort(void);

		void PushInBuffer(char nNewValue);
		BOOL PopInBuffer(char* data);
		void PushOutBuffer(char nNewValue);
    BOOL PopOutBuffer(char* data);
		void OutBufferRest();
		void InBufferRest();

		void SetSettings(LPCTSTR lpszNewValue);
		void SetRXEnable(BOOL bNewValue);
		BOOL GetRXEnable(void);
		void SetTXEnable(BOOL bNewValue);
		BOOL GetTXEnable(void);
		void SetRXNEIE(BOOL bNewValue);
		BOOL GetRXNEIE(void);
		void SetTCIEnable(BOOL bNewValue);
		BOOL GetTCIEnable(void);

		void SetCommTimeouts(unsigned int NewValue); //…Ë÷√≥¨ ± NewValue
		unsigned int GetCommTimeouts(void);
		CByteArray SetOutput(LPCByteArray NewValue);///////////////
		void Send_byte(unsigned char data);
		void TX_TASK(void);
		unsigned short RX_TASK(char *buf,unsigned short cnt);
};

#endif 

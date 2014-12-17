#include "mscomm.h"

 

CByteArray::CByteArray()
{
	length=0;
	data=NULL;
}

CByteArray::~CByteArray()
{
}

void CByteArray::SetSize(unsigned short NewVale)
{
  length=NewVale;
}
 
void CByteArray::SetDataPoint(char *p)
{
 data=p;
}

void CByteArray::SetAs(unsigned short index,char DA)
{
	data+=index;
	*data=DA; 
	data-=index;
}


unsigned short CByteArray::GetLength(void)
{
	return(length);
}

char* CByteArray::GetDataPoint(void)
{
	return(data);
}
  
  
CMSComm::CMSComm()
{
	CMSComm_CR1=(1<<13);/////////
	CMSComm_CR2=0;
	CMSComm_CR3=0;
	CMSComm_GTPR=0;
	wait_to_send=TRUE;
	CMSComm_timeout=0;
}


CMSComm::~CMSComm()
{

}

void CMSComm::SetInBuffer(LPCByteArray nNewValue)
{
	FifoIn.SetBuffer((unsigned char*)((*nNewValue).GetDataPoint()),(*nNewValue).GetLength());
}


CByteArray CMSComm::GetInBuffer()
{
	CByteArray array_tmp;

	array_tmp.SetDataPoint((char*)FifoIn.GetBuffer());
	array_tmp.SetSize(FifoIn.GetBufferLength());///

	return array_tmp;
}

void CMSComm::SetOutBuffer(LPCByteArray nNewValue)
{
	FifoOut.SetBuffer((unsigned char*)((*nNewValue).GetDataPoint()),(*nNewValue).GetLength());
}

CByteArray CMSComm::GetOutBuffer()
{
	CByteArray array_tmp;

	array_tmp.SetDataPoint((char*)FifoOut.GetBuffer());
	array_tmp.SetSize(FifoOut.GetBufferLength());///

	return array_tmp;
}


void CMSComm::OutBufferRest()
{
  FifoOut.ReSet();
}

void CMSComm::InBufferRest()
{
  FifoIn.ReSet();
}
	  
void CMSComm::PushInBuffer(char nNewValue)
{
  FifoIn.Push(nNewValue);
}

BOOL CMSComm::PopInBuffer(char* data)
{
	return FifoIn.Pop((U8*)data);
}



void CMSComm::PushOutBuffer(char nNewValue)
{
  FifoOut.Push(nNewValue);
}

BOOL CMSComm::PopOutBuffer(char* data)
{
	return FifoOut.Pop((U8*)data);
}



	   
void CMSComm::SetCommPort(char NewValue) 
{
 #define UE 0x2000

 CMSComm_port = NewValue;
 CMSComm_CR1 |= UE;
 switch(CMSComm_port)
  {
    case 1:
			RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
			USART1->CR1 = CMSComm_CR1;
		  // interrupt config
			NVIC->IP[37] = 0x02;
			NVIC->ICPR[1] |= NVIC_ICPR_CLRPEND_5;
			NVIC->ISER[1] |= NVIC_ISER_SETENA_5;
	  break;

	case 2:
			RCC->APB1ENR |= RCC_APB1ENR_USART2EN;	///clk enable
			USART2->CR1=CMSComm_CR1;
			// interrupt config
			NVIC->IP[38] = 0x02;
			NVIC->ICPR[1] |= NVIC_ICPR_CLRPEND_6;
			NVIC->ISER[1] |= NVIC_ISER_SETENA_6;
	break;

	case 3:
			RCC->APB1ENR |= RCC_APB1ENR_USART3EN;	///clk enable
			USART3->CR1=CMSComm_CR1;
			 // interrupt config
			NVIC->IP[39] = 0x02;
			NVIC->ICPR[1] |= NVIC_ICPR_CLRPEND_7;
			NVIC->ISER[1] |= NVIC_ISER_SETENA_7;
	break;
	default:break;
  }
}

char CMSComm:: GetCommPort(void)
{
  return (CMSComm_port);
} 


void CMSComm::SetRXEnable(BOOL bNewValue)
{
  if(bNewValue) CMSComm_CR1 |= USART_CR1_RE;
	else CMSComm_CR1&=(~USART_CR1_RE);
  

  switch(CMSComm_port)
  {
    case 1:
			if((*(volatile unsigned *)(PERIPH_BB_BASE+(0x00010004+0)*32+2*4)))//AFIO_MAPR0x40010000 USART1_REMAP
			{
				 /* Configure USART1 Rx (PB.6) as input floating */
				 _GpioInitialAsPInput(B,L,6);
			}
			else
			{
				/* Configure USART1 Rx (PA.10) as input floating */
				 _GpioInitialAsPInput(A,H,10);
			}
			USART1->CR1=CMSComm_CR1;
	break;

	case 2:
	 if((*(volatile unsigned *)(PERIPH_BB_BASE+(0x00010004+0)*32+3*4)))//AFIO_MAPR0x40010000 USART2_REMAP
	 {
	  /* Configure USART2 Rx (PD.6) as input floating */
     _GpioInitialAsPInput(D,L,6);
	 }
	 else
	 {
	   /* Configure USART2 Rx (PA.3) as input floating */
      _GpioInitialAsPInput(A,L,3);
	 }
	 USART2->CR1=CMSComm_CR1;
	break;

	case 3:
	 if((*(volatile unsigned *)(PERIPH_BB_BASE+(0x00010004+0)*32+4*4)))//AFIO_MAPR0x40010000 USART3_REMAP
	 {
			if((*(volatile unsigned *)(PERIPH_BB_BASE+(0x00010004+0)*32+5*4)))
			{
			 /* Configure USART3 Rx (PD.9) as input floating */
				_GpioInitialAsPInput(D,H,9);
			}
			else
			{
			 /* Configure USART3 Rx (PC.11) as input floating */
			 _GpioInitialAsPInput(C,H,11);
			}
	 }
	 else
	 {
	   /* Configure USART3 Rx (PB.11) as input floating */
     _GpioInitialAsPInput(B,H,11);
	 }
	 USART3->CR1=CMSComm_CR1;
	break;

	default:break;
  }
}


BOOL CMSComm::GetRXEnable(void)
{
  if(CMSComm_CR1 & USART_CR1_RE)return TRUE;
  else return FALSE;
}


void CMSComm::SetTXEnable(BOOL bNewValue)
{
  if(bNewValue)CMSComm_CR1 |= USART_CR1_TE;
  else CMSComm_CR1 &= (~USART_CR1_TE);

 switch(CMSComm_port)
  {
    case 1:
	 if((*(volatile unsigned *)(PERIPH_BB_BASE+(0x00010004+0)*32+2*4)))//AFIO_MAPR0x40010000 USART1_REMAP
	 {
      /* Configure USART1 Tx (PB.7) as alternate function push-pull */
       _GpioInitialAsPInput(B,L,7);
	 }
	 else
	 {
      /* Configure USART1 Tx (PA.9) as alternate function push-pull */
      _GpioInitialAsPInput(A,H,9);
	 }
	 USART1->CR1=CMSComm_CR1;
	break;

	case 2:
	 if((*(volatile unsigned *)(PERIPH_BB_BASE+(0x00010004+0)*32+3*4)))//AFIO_MAPR0x40010000 USART2_REMAP
	 {
      /* Configure USART2 Tx (PD.05) as alternate function push-pull */
      _GpioInitialAsPInput(D,L,5);
	 }
	 else
	 {
       /* Configure USART2 Tx (PA.02) as alternate function push-pull */
       _GpioInitialAsPInput(A,L,2);
	 }
	 USART2->CR1=CMSComm_CR1;
	break;

	case 3:
	 if((*(volatile unsigned *)(PERIPH_BB_BASE+(0x00010004+0)*32+4*4)))//AFIO_MAPR0x40010000 USART3_REMAP
	 {
			if((*(volatile unsigned *)(PERIPH_BB_BASE+(0x00010004+0)*32+5*4)))
			{
				 /* Configure USART3 Tx (PD.08) as alternate function push-pull */
				_GpioInitialAsPInput(D,H,8);
			}
			else
			{
				 /* Configure USART3 Tx (PC.10) as alternate function push-pull */
				 _GpioInitialAsPInput(C,H,10);
			}
	 }
	 else
	 {
       /* Configure USART3 Tx (PB.10) as alternate function push-pull */
       _GpioInitialAsPInput(B,H,10);
	 }
	 USART3->CR1=CMSComm_CR1;
	break;

	default:break;
  }
}

BOOL CMSComm::GetTXEnable(void)
{
  if(CMSComm_CR1 & USART_CR1_TE)return TRUE ;
  else return FALSE;
}

void CMSComm::SetRXNEIE(BOOL bNewValue)
{
  
  if(bNewValue)CMSComm_CR1 |= USART_CR1_RXNEIE;
  else CMSComm_CR1 &= (~USART_CR1_RXNEIE);
  
	switch(CMSComm_port)
	{
		case 1:
			USART1->CR1=CMSComm_CR1;
			USART1->SR&=(~USART_CR1_RXNEIE);
		break;

		case 2:
			USART2->CR1=CMSComm_CR1;
			USART2->SR&=(~USART_CR1_RXNEIE);
		break;

		case 3:
			USART3->CR1=CMSComm_CR1;
			USART3->SR&=(~USART_CR1_RXNEIE);
		break;
		default:break;
	}
}

BOOL CMSComm::GetRXNEIE(void)
{ 
  if(CMSComm_CR1&USART_CR1_RXNEIE)return TRUE ;
  else return FALSE ;
}

void CMSComm::SetTCIEnable(BOOL bNewValue)
{
  if(bNewValue)CMSComm_CR1|=USART_CR1_TCIE;
  else CMSComm_CR1&=(~USART_CR1_TCIE);
  
  switch(CMSComm_port)
  {
    case 1:
	    USART1->CR1=CMSComm_CR1;
	  break;

	  case 2:
	    USART2->CR1=CMSComm_CR1;
	  break;

	  case 3:
	    USART3->CR1=CMSComm_CR1;
	  break;
	  default:break;
  }
}

BOOL CMSComm::GetTCIEnable(void)
{
  if(CMSComm_CR1&(USART_CR1_TCIE))return(TRUE);
  else return(FALSE);
}

void CMSComm::SetSettings(LPCTSTR lpszNewValue)
{
 //SetSettings("1200,e,8,1"); //设置波特率等参数

	const char *p;
	char *buffer,tmp;
	float USARTDIV;
	unsigned short DIV_Mantissa,
								 DIV_Fraction,
				         USART_BRR;
	long clk_div;

	tmp=0;
	p=lpszNewValue;
  buffer = (char*)malloc(32);
	memset(buffer,0,10);
	
	do
	{
		buffer[tmp]=*p;
		tmp++;
		p++;
	}while(*p!=',');
  
 CMSComm_bud=atol(buffer);
 /////////////////////////////////////////////////////////////////////////
 if(CMSComm_port==1)
 {
   clk_div=(RCC->CFGR&(7<<11));
   clk_div>>=11;
 }
 else 
 {
   clk_div=(RCC->CFGR&(7<<8));
   clk_div>>=8;
 }
 if(clk_div&(1<<2))
 {
   clk_div&=(~(1<<2));//////////
   clk_div++;
   clk_div=1<<clk_div;
 }
 else clk_div=1;

 USARTDIV=(float)((double)(F_CPU/16)/CMSComm_bud/clk_div);
 DIV_Mantissa=(short)USARTDIV;
 DIV_Fraction=((USARTDIV-DIV_Mantissa)*16);//+0.5);
 DIV_Fraction&=0x0F;
 USART_BRR=DIV_Mantissa<<4;
 USART_BRR+=DIV_Fraction;
 /////////////////////////////////////////////////////////////////////////
  
 p++;
 CMSComm_CR1 &= (~(USART_CR1_M|USART_CR1_PCE));
 if(*p=='e')CMSComm_CR1 |= USART_CR1_PCE;
 else if(*p=='n');
 else CMSComm_CR1 |= (USART_CR1_PCE|USART_CR1_PS);

 p+=2;
 switch(*p)
 {
	 case '8': break; 
	 case '9':
	   CMSComm_CR1 |= USART_CR1_M;
	 break;
	 default:break;
 }

 p+=2;
 CMSComm_CR2&=(~USART_CR2_STOP);
 if(*p=='2')CMSComm_CR2 |= USART_CR2_STOP_1;
 switch(CMSComm_port)
  {
    case 1:
	    USART1->CR1=CMSComm_CR1;
	    USART1->CR2=CMSComm_CR2;
	    USART1->BRR=USART_BRR;
	  break;

	  case 2:
	    USART2->CR1=CMSComm_CR1;
	    USART2->CR2=CMSComm_CR2;
	    USART2->BRR=USART_BRR;
	  break;

	  case 3:
	    USART3->CR1=CMSComm_CR1;
	    USART3->CR2=CMSComm_CR2;
	    USART3->BRR=USART_BRR;
  	break;
	  default:break;
  }
}

void CMSComm::Send_byte(unsigned char data)
{ 
 #define TXE 7
 #define TC 6
 //bit_word_addr = bit_band_base + (byte_offset×32) + (bit_number×4)

 wait_to_send=FALSE;
 switch(CMSComm_port)
  {
		case 1:
			#ifndef USART_TXC_INTERRUPT_ENABLE
			(*(volatile unsigned *)(PERIPH_BB_BASE+(0x00013800+0)*32+TC*4))=0;
			USART1->DR=data;
			while(!(*(volatile unsigned *)(PERIPH_BB_BASE+(0x00013800+0)*32+TC*4)));
			#else
			// wait TXBuf empty
			while(!(*(volatile unsigned *)(PERIPH_BB_BASE+(0x00013800+0)*32+TXE*4)));
			USART1->DR=data;
			#endif
		break;

		case 2:
			#ifndef USART_TXC_INTERRUPT_ENABLE
			(*(volatile unsigned *)(PERIPH_BB_BASE+(0x0004400+0)*32+TC*4))=0;
			USART2->DR=data;
			while(!(*(volatile unsigned *)(PERIPH_BB_BASE+(0x0004400+0)*32+TC*4)));
			#else
			// wait TXBuf empty
			while(!(*(volatile unsigned *)(PERIPH_BB_BASE+(0x0004400+0)*32+TXE*4)));
			USART2->DR=data;
			#endif 
		break;

		case 3:
			#ifndef USART_TXC_INTERRUPT_ENABLE
			(*(volatile unsigned *)(PERIPH_BB_BASE+(0x0004800+0)*32+TC*4))=0;
			USART3->DR=data;
			while(!(*(volatile unsigned *)(PERIPH_BB_BASE+(0x0004800+0)*32+TC*4)));
			#else
			// wait TXBuf empty
			while(!(*(volatile unsigned *)(PERIPH_BB_BASE+(0x0004800+0)*32+TXE*4)));
			USART3->DR=data;
			#endif 
		break;
		default:break;
  }
 
}



void CMSComm::SetCommTimeouts(unsigned int NewValue)
{

}

unsigned int CMSComm::GetCommTimeouts(void)
{
  return 0;
}

       
CByteArray CMSComm::SetOutput(LPCByteArray NewValue)
{
	CByteArray tmpArray=*NewValue;
	#ifndef USART_TXC_INTERRUPT_ENABLE
	unsigned char len, tmpcnt;

	char *pdata=(*NewValue).GetDataPoint(); 

	len=(*NewValue).GetLength();
	for(tmpcnt=0;tmpcnt<len;tmpcnt++)
	{
		Send_byte(*pdata);
		pdata++;
	}
	#else
	tmpArray=GetOutBuffer();
	SetOutBuffer(NewValue);
	#endif
	return tmpArray;
}




void CMSComm::TX_TASK(void)
{
	unsigned char tmp;
	
	if(wait_to_send)
	{
		if(FifoOut.Pop(&tmp))
			Send_byte(tmp);
	}
}

unsigned short CMSComm::RX_TASK(char *buf,unsigned short cnt)
{
	unsigned char tmp;
	
	if(buf != NULL)
	{
		if(FifoIn.Pop(&tmp))
		{
		  buf[cnt] = tmp;
			cnt++;
	  }
	}
	else return 0;
  return cnt;
}


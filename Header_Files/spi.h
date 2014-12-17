#ifndef __SPI_H__
#define __SPI_H__

#ifdef __cplusplus
 extern "C" {
#endif
	 
#include "pincfg.h"
#include "delay.h"
#include "typedef.h"
#include "stm32f10x.h"	
  

extern void SPI1_IRQHandler(void);

typedef enum __BIT_ORDER__{FLSB,FMSB}BIT_ORDER;
typedef enum __MST_SLV__{SLAVE,MASTER}MST_SLV;
typedef enum __CLK_POLARITY__{CLK_START_EDGE_FALLING,CLK_START_EDGE_RISING}CLK_POLARITY;
typedef enum __CLK_PHASE__{DATA_SET_AT_TRAILING_EDGE,DATA_SET_AT_LEADING_EDGE}CLK_PHASE;

extern U32 Log2(U32 x); 

extern void SpiInitial(U8 NS_PLL, //2,4,8,16,32,64,128
												BOOL master,
												BOOL MSB_AT_FIRST,
												BOOL CLK_STR_RISING,
												BOOL DATA_SET_AT_LEADING,
												void *isr); 

extern void SpiDisableInterrupt(void);

extern void SpiEnableInterrupt(void);

extern U8 SpiExchangeByte(U8 data);

extern BOOL SpiPoll(U8*data);

extern U8 GetSpiData(void);
	 
extern void SpiSlaveSynchronize(void);

#ifdef __cplusplus
}											
#endif

#endif



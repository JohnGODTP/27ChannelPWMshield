#include "spi.h"


static ISR SPI1_ISR;


void SPI1_IRQHandler(void)
{
  if(SPI1->SR & SPI_SR_RXNE)SPI1_ISR();
	else if(SPI1->SR & SPI_SR_CRCERR)SPI1->SR = 0;
}


U32 Log2(U32 x)
{
	U32 tmpInt;
	U32 result;
	
	result = 0;
	tmpInt = 1;
	while(tmpInt < x)
	{
		tmpInt <<=2;
		result ++;
	}
  return result;
}

void SpiInitial(U8 NS_PLL, //2,4,8,16,32,64,128,256
								BOOL master,
								BOOL MSB_AT_FIRST,
								BOOL CLK_STR_RISING,
								BOOL DATA_SET_AT_LEADING,
								void *isr)
{
	RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;
	RCC->APB2RSTR |= RCC_APB2RSTR_SPI1RST;
	_CsPinInitial();
  _SckPinInitial();
  _MisoPinInitial();
  _MosiPinInitial();
	delay_us(10);
	RCC->APB2RSTR &= ~RCC_APB2RSTR_SPI1RST;
	SPI1->CR1 |= (SPI_CR1_SPE | SPI_CR1_SSM );
	if(master)SPI1->CR1 |= SPI_CR1_MSTR;
	if(!MSB_AT_FIRST)SPI1->CR1 |= SPI_CR1_LSBFIRST;
	if(!CLK_STR_RISING)SPI1->CR1 |= SPI_CR1_CPOL;
	if(!DATA_SET_AT_LEADING)SPI1->CR1 |= SPI_CR1_CPHA;
  NS_PLL = Log2(NS_PLL) & 0x07;
	if(NS_PLL)NS_PLL-=1;
	SPI1->CR1 |= (NS_PLL <<3);
	if(isr != NULL)
	{
		SPI1_ISR = (ISR)isr;
		SPI1->CR2 |= (SPI_CR2_ERRIE | SPI_CR2_RXNEIE );
		// interrupt config
	  NVIC->IP[35] = 0x02;
	  NVIC->ICPR[1] |= NVIC_ICPR_CLRPEND_3;
	  NVIC->ISER[1] |= NVIC_ISER_SETENA_3;
	}
	else SPI1_ISR = NULL;
	
}


void SpiDisableInterrupt(void)
{
	while(SPI1->SR & SPI_SR_BSY)
	{
		;
	}
	SPI1->CR2 &= ~(SPI_CR2_ERRIE | SPI_CR2_RXNEIE);
}

void SpiEnableInterrupt(void)
{
	while(SPI1->SR & SPI_SR_BSY)
	{
		;
	}
	SPI1->CR2 |= (SPI_CR2_ERRIE | SPI_CR2_RXNEIE );
}


BOOL SpiPoll(U8*data)
{
	if(SPI1->SR & SPI_SR_RXNE)
	{
		*data = SPI1->DR;
		return TRUE;
	}
	return FALSE;
}


U8 GetSpiData(void)
{
	U8 Result;
	
	Result = SPI1->DR;
	return Result;
}


U8 SpiExchangeByte(U8 data)
{
	U8 Result;
	
	SPI1->DR = data;
  while(SPI1->SR & SPI_SR_BSY)
	{
		;
	}
	Result = SPI1->DR;
  return Result;
}


void SpiSlaveSynchronize(void)
{
	SPI1->CR1 |= SPI_CR1_SSI;
	SPI1->CR1 &= ~SPI_CR1_SSI;
}


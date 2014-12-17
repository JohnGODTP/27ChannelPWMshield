#include "delay.h"



void delay_ms(unsigned short ns)
{
  unsigned long tmp;
  
  tmp=(unsigned long)ns*ms;
  
  while(tmp>20)tmp--;
}

void delay_us(unsigned short ns)
{
  unsigned long tmp;
  
   tmp=(unsigned long)ns*us;
  
   while(tmp>20)tmp--;
}


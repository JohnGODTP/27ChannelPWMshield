#ifndef __DELAY_H__
#define __DELAY_H__


#ifndef SYS_CLK
 #define SYS_CLK 72000000
#endif
#define ms (SYS_CLK/4000)
#define us (SYS_CLK/4000000)


extern void delay_ms(unsigned short ns);

extern void delay_us(unsigned short ns);

#endif

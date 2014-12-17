#ifndef __TYPE_DEF_H__
#define __TYPE_DEF_H__


typedef          char   CHAR;
typedef unsigned char   UCHAR;
typedef unsigned char   U8;
typedef UCHAR BYTE;
typedef signed char     S8;

typedef unsigned short  USHORT;
typedef unsigned short  U16;
typedef U16 WORD;

typedef unsigned int    U32;
typedef unsigned long   ULONG;
typedef ULONG DWORD;

typedef unsigned long long U64;
typedef unsigned int    BOOL;
typedef char           *PCHAR;
typedef unsigned char  *PUCHAR;

typedef const char* LPCTSTR ;
//typedef  bool BOOL ;

#ifndef NULL
  #define NULL 0
#endif

#ifndef TRUE
  #define TRUE 1
#endif

#ifndef FALSE
  #define FALSE 0
#endif


#define __SFR_MEM32(x) (*((volatile unsigned int*)(x)))

#define VALUE_OFFSET_IN_STRUCT(struct_name,value_name) ((unsigned long)&(((struct_name*)0)->value_name))
// bit_word_offset = (byte_offset x 32) + (bit_number x 4)
// bit_word_addr = bit_band_base + bit_word_offset
#define __SFR_IO_BIT(byte_offset,bit_number) __SFR_MEM32(((unsigned long)PERIPH_BB_BASE + ((unsigned long)byte_offset<<5) + ((unsigned long)bit_number<<2)))
#define __SFR_RAM_BIT(byte_offset,bit_number) __SFR_MEM32(((unsigned long)SRAM_BB_BASE + ((unsigned long)byte_offset<<5) + ((unsigned long)bit_number<<2)))

typedef void(*ISR)(void);								
#define F_CPU ((U32)72000000)
#define F_APB1  F_CPU/2
#define F_APB2  F_CPU

#endif


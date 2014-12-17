#ifndef __RING_BUFFER_DEF_H__
#define __RING_BUFFER_DEF_H__

extern "C"{
#include"typedef.h"
}


#define _EnableCpuInttrupt() __asm("CPSIE I")
#define _DisableCpuInttrupt() __asm("CPSID I")

template<class T1>
	
class RingBuffer{
	private:
		T1* pBuffer;
    U32 bufSize;
    U32 readPoint;
	  U32 writePoint;
	  U32 emptySpace;
	  BOOL empty;
	public:
		RingBuffer();
	  ~RingBuffer();
	  void SetBuffer(T1* pBuf,U32 size);
	  T1 *GetBuffer(void);
	  U32 GetBufferLength(void);
		void ReSet(void);
		BOOL Push(T1 data);
	  BOOL Pop(T1* data);
};
#endif

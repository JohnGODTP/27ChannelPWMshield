#include "ring_buffer_def.h"



template<typename  T1>
RingBuffer<T1>::RingBuffer()
{
	pBuffer = NULL;
  bufSize = 0x00000000;
  readPoint = 0x00000000;
	writePoint = 0x00000000;
	emptySpace = 0x00000000;
	empty = TRUE;
}

template<typename T1>
RingBuffer<T1>:: ~RingBuffer()
{
	
}


template<typename T1>
void RingBuffer<T1>::SetBuffer(T1* pBuf,U32 size)
{
	bufSize = size;
	pBuffer = pBuf;
	emptySpace = bufSize;
}

template<typename T1>
T1* RingBuffer<T1>::GetBuffer(void)
{
	return pBuffer;
}


template<typename T1>
U32 RingBuffer<T1>::GetBufferLength(void)
{
	return bufSize;
}


template<typename T1>
void RingBuffer<T1>::ReSet(void)
{
  _DisableCpuInttrupt();
	readPoint = 0x00000000;
	writePoint = 0x00000000;
	emptySpace = bufSize;
	empty = TRUE;
  _EnableCpuInttrupt();
}

template<typename T1>
BOOL RingBuffer<T1>::Push(T1 data)
{
	if(emptySpace)
	{
    _DisableCpuInttrupt();
		if(writePoint == bufSize)
		{
			writePoint = 1;
			pBuffer[0] = data;
		}
		else pBuffer[writePoint++] = data;
		emptySpace --;
    _EnableCpuInttrupt();
    return TRUE;
	}
	else return FALSE;
}

template<typename T1>
BOOL RingBuffer<T1>::Pop(T1* data)
{
	if(emptySpace >= bufSize)return FALSE;
  _DisableCpuInttrupt();
	if(readPoint == bufSize)
	{
		readPoint = 1;
		*data = pBuffer[0];
	}
	else *data = pBuffer[readPoint++];
	emptySpace ++;
	_EnableCpuInttrupt();
  return TRUE;
}

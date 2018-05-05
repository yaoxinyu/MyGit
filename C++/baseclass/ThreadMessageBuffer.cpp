#include "ThreadMessageBuffer.h"
#include <assert.h>

ThreadMessageBuffer::ThreadMessageBuffer(const unsigned char* buffer, int bufferSize)
	: m_Buffer(NULL)
	, m_BufferSize(0)
	, m_Length(0)
{
	assert(bufferSize > 0 && bufferSize < MAX_MESSAGEBUFFER_LENGTH);
	if (Init(bufferSize))
	{
		if (NULL != buffer && NULL != m_Buffer && m_BufferSize >= bufferSize)
		{
			memcpy_s(m_Buffer, m_BufferSize, buffer, bufferSize);
		}
	}
}

ThreadMessageBuffer::ThreadMessageBuffer(int bufferSize)
	: m_Buffer(NULL)
	, m_BufferSize(0)
	, m_Length(0)
{
	assert(bufferSize > 0 && bufferSize < MAX_MESSAGEBUFFER_LENGTH);
	Init(bufferSize);
}

ThreadMessageBuffer::~ThreadMessageBuffer()
{
	if (NULL != m_Buffer)
	{
		delete[] m_Buffer;
		m_Buffer = NULL;
	}
	m_BufferSize = 0;
	m_Length = 0;
}

bool ThreadMessageBuffer::Init(int bufferSize)
{
	if (bufferSize > 0 && bufferSize <= MAX_MESSAGEBUFFER_LENGTH)
	{
		// 考虑用小内存管理，避免频繁new delete
		m_Buffer = new unsigned char(bufferSize);
		if (NULL != m_Buffer)
		{
			m_BufferSize = bufferSize;
			m_Length = bufferSize;
			return true;
		}
	}
	return false;
}


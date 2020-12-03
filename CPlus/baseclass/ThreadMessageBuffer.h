#pragma once

#include <memory>
#define MAX_MESSAGEBUFFER_LENGTH    2 * 1024 * 1024


class ThreadMessageBuffer
{
public:
    ThreadMessageBuffer(const unsigned char* buffer, int length);
    ThreadMessageBuffer(int length);
    virtual ~ThreadMessageBuffer();

    unsigned char * GetBuffer()
    {
        return m_Buffer;
    }

    int GetBufferSize()
    {
        return m_BufferSize;
    }

protected:
    // ³õÊ¼»¯ÄÚ´æ
    bool Init(int bufferSize);

protected:
    int m_Length;
    int m_BufferSize;
    unsigned char * m_Buffer;
};

typedef std::shared_ptr<ThreadMessageBuffer>	MessageBufferPtr;
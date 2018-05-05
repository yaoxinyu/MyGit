#include "ThreadBase.h"
#include <process.h>

CThreadBase::CThreadBase()
{
}

CThreadBase::~CThreadBase()
{

}

bool CThreadBase::Terminate(void)
{
	_endthreadex(0);
	return TRUE;
}

HANDLE CThreadBase::GetThreadHandle()
{
	return m_hthreadHandle;
}

void CThreadBase::Start()
{
	unsigned int threadID;
	m_hthreadHandle = (HANDLE)_beginthreadex(NULL, 0, ThreadFunc, this, 0, &threadID);
	m_ThreadID = threadID;
}

unsigned __stdcall CThreadBase::ThreadFunc(void* pVoid)
{
	CThreadBase* pThread = (CThreadBase*)pVoid;
	if (pThread)
	{
		pThread->Run();
	}

	return 0;
}

int  CThreadBase::GetThreadID(void)
{
	return m_ThreadID;
}

void CThreadBase::SetThreadName(const std::string& threadName)
{
	m_ThreadName = threadName;
}

std::string CThreadBase::GetThreadName()
{
	return m_ThreadName;
}
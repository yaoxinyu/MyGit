#pragma once

#include <Windows.h>
#include <string>

// �̻߳���  
class CThreadBase
{
public:
	CThreadBase();
	virtual ~CThreadBase();

	void Start();
	// ��ȡ�߳�ID  
	int GetThreadID(void);
	// ��ȡ�߳̾�� 
	HANDLE GetThreadHandle();
	//�����߳�����  
	void SetThreadName(const std::string& threadName);
	//��ȡ�߳�����  
	std::string GetThreadName();

	virtual void Run() = 0;

	bool Terminate(void);
private:
	unsigned int m_ThreadID; //�߳�ID  
	std::string  m_ThreadName; //�߳�����  
	HANDLE m_hthreadHandle; //�߳̾��   
protected:
	static unsigned __stdcall ThreadFunc(void* pVoid); 
};
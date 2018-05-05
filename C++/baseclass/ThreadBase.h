#pragma once

#include <Windows.h>
#include <string>

// 线程基类  
class CThreadBase
{
public:
	CThreadBase();
	virtual ~CThreadBase();

	void Start();
	// 获取线程ID  
	int GetThreadID(void);
	// 获取线程句柄 
	HANDLE GetThreadHandle();
	//设置线程名字  
	void SetThreadName(const std::string& threadName);
	//获取线程名字  
	std::string GetThreadName();

	virtual void Run() = 0;

	bool Terminate(void);
private:
	unsigned int m_ThreadID; //线程ID  
	std::string  m_ThreadName; //线程名字  
	HANDLE m_hthreadHandle; //线程句柄   
protected:
	static unsigned __stdcall ThreadFunc(void* pVoid); 
};
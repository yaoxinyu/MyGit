#pragma once

#include "TaskBase.h"
#include "Lock.h"
#include <list>

class CTaskQueue
{
public:
	CTaskQueue();
	~CTaskQueue();

	void PushTask(CTaskBasePtr pTask);
	CTaskBasePtr PopTask();
private:
	std::list<CTaskBasePtr> m_taskList;
	CLock m_queueLock;
};
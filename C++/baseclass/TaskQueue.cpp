#include "TaskQueue.h"

CTaskQueue::CTaskQueue()
{
}

CTaskQueue::~CTaskQueue()
{
}

void CTaskQueue::PushTask(CTaskBasePtr pTask)
{
	if (pTask)
	{
		AutoLock lock(m_queueLock);
		m_taskList.push_back(pTask);
	}
}

CTaskBasePtr CTaskQueue::PopTask()
{
	CTaskBasePtr pTask;

	AutoLock lock(m_queueLock);
	pTask = m_taskList.front();
	m_taskList.pop_front();

	return pTask;
}
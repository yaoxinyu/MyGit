#include "ThreadPool.h"

CThreadPool::CThreadPool(int threadNum)
	: threadNum_(threadNum)
	, isRunning_(false)
{
}

CThreadPool::~CThreadPool()
{
	if (isRunning_)
	{
		Stop();
	}
}

void CThreadPool::Start()
{
	isRunning_ = true;
	for (int i = 0; i < threadNum_; ++i)
	{
		m_threads.push_back(std::make_shared<std::thread>(&CThreadPool::DoWork, this));
	}
}

void CThreadPool::Stop()
{
	// 线程池关闭，并通知所有线程可以取任务了
	{
		std::unique_lock<std::mutex> lock(m_TaskLock);
		isRunning_ = false;
		hasTaskCond_.notify_all();
	}
	for (int i = 0; i < m_threads.size(); ++i)
	{
		auto t = m_threads[i];
		if (t->joinable())
			t->join();
	}
}
//添加任务
void CThreadPool::PostTask(CTaskBasePtr pTask)
{
	if (isRunning_) {
		std::unique_lock<std::mutex> lock(m_TaskLock);
		m_taskList.push_back(pTask);
		hasTaskCond_.notify_one();
	}
}

void CThreadPool::DoWork()
{
	while (isRunning_)
	{
		std::unique_lock<std::mutex> lock(m_TaskLock);
		if (m_taskList.empty())
		{
			hasTaskCond_.wait(lock);
		}

		if (!m_taskList.empty())
		{
			CTaskBasePtr pTask = m_taskList.front();
			m_taskList.pop_front();

			if (pTask)
			{
				pTask->DoWork();
			}
		}
	}
}
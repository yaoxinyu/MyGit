#pragma once

#ifndef MY_THREADPOOL_H
#define MY_THREADPOOL_H

#include <thread>
#include <mutex>
#include <condition_variable>
#include <memory>
#include <vector>
#include <list>
#include "TaskBase.h"

class CThreadPool 
{
public:
    explicit CThreadPool(int threadNum);
    ~CThreadPool();
    CThreadPool(const CThreadPool&) = delete;
    CThreadPool& operator=(const CThreadPool& rhs) = delete;

    void PostTask(CTaskBasePtr pTask);
    void Start();
    void Stop();
private:
    void DoWork();
private:
    bool isRunning_;
    int threadNum_;
    
    std::mutex m_TaskLock;
    std::condition_variable hasTaskCond_;
    std::list<CTaskBasePtr> m_taskList;
    std::vector<std::shared_ptr<std::thread>> m_threads;
};

#endif
#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <list>

template <class T>
class myQueue {
public:
    myQueue();
    ~myQueue();

    void enqueue(const T& element);
    T    dequeue();
    T    top();

    bool empty() const
    {
        return _queueSize == 0;
    }

    size_t size() const
    {
        return _queueSize;
    }

private:
    std::list<T> _queue;
    size_t       _queueSize;
};

template <class T>
myQueue<T>::myQueue()
    : _queueSize(0)
{
}

template <class T>
myQueue<T>::~myQueue()
{
}

template <class T>
void myQueue<T>::enqueue(const T& element)
{
    _queue.push_back(element);
    ++_queueSize;
}

template <class T>
T myQueue<T>::dequeue()
{
    T item;
    if (!_queue.empty()) {
        item = _queue.front();
        _queue.pop_back();
        --_queueSize;
    }

    return item;
}

template <class T>
T myQueue<T>::top()
{
    T item;
    if (!_queue.empty())
        item = _queue.front();

    return item;
}

#endif  // MYQUEUE_H

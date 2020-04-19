#ifndef MYSTACK_H
#define MYSTACK_H

#include <list>

using namespace std;

template <class T>
class myStack {
public:
    myStack();
    ~myStack();

public:
    void push(const T& element);
    void pop();
    T    top();

    bool empty() const
    {
        return _stackSize == 0;
    }

    size_t size() const
    {
        return _stackSize;
    }

private:
    list<T> _stack;
    size_t  _stackSize;
};

template <class T>
myStack<T>::myStack()
    : _stackSize(0)
{
}

template <class T>
myStack<T>::~myStack()
{
}

template <class T>
void myStack<T>::push(const T& element)
{
    _stack.push_front(element);
    ++_stackSize;
}

template <class T>
void myStack<T>::pop()
{
    if (!_stack.empty()) {
        _stack.pop_front();
        --_stackSize;
    }
}

template <class T>
T myStack<T>::top()
{
    T item;
    if (!_stack.empty()) {
        item = _stack.front();
    }

    return item;
}

#endif  // MYSTACK_H

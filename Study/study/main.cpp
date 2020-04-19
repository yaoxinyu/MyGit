#include <iostream>
#include <string>
#include "myQueue.h"
#include "myStack.h"
using namespace std;

void runTestMyQueue()
{
    myQueue<string> q;
    cout << "IsEmpty: " << q.empty() << endl;
    q.enqueue("hello");
    q.enqueue("world");
    q.enqueue("how");
    q.enqueue("are");
    q.enqueue("you");
    cout << "Queue Size: " << q.size() << endl;
    cout << "Queue top item: " << q.top() << endl;
    cout << "Queue Size: " << q.size() << endl;
    q.dequeue();
    q.dequeue();
    q.dequeue();
    cout << "After delete 3 items, Queue Size: " << q.size() << endl;
    cout << "Queue top item: " << q.top() << endl;
    q.dequeue();
    q.dequeue();
    cout << "Then delete 2 items, Queue Size: " << q.size() << endl;
    cout << "IsEmpty: " << q.empty() << endl;
    q.enqueue("Good");
    q.enqueue("Bye");
    cout << "Then add 2 items, Queue top item: " << q.top() << endl;
    cout << "IsEmpty: " << q.empty() << endl;
}

void runTestMyStack()
{
    myStack<int> s;
    for(int i = 0; i < 5; ++i)
    {
        s.push(i);
        cout << "Stack push item: " << i << endl;
    }
    for(int i = 0; i < 5; ++i)
    {
        cout << "Stack pop item: " << s.top() << endl;
        s.pop();
    }
    cout << "Stack is empty: " << s.empty() << endl;
    s.push(2);
    cout << "Push 1 item, Stack is empty: " << s.empty() << endl;
    s.push(-4);
    cout << "Then push -4, stack size: " << s.size() << endl;
    cout << "Stack top item: " << s.top() << endl;
}

int main()
{
    runTestMyQueue();
    runTestMyStack();

    return 0;
}

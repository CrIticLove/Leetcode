#include <iostream>
using namespace std;

class RingQueue
{
private:
    int size;
    int front;
    int rear;
    int *data;

public:
    RingQueue(int size) : size(size + 1)
    {
        front = 0;
        rear = 0;
        data = new int[size + 1];
    }
    ~RingQueue()
    {
        delete data;
    }
    bool isEmpty()
    {
        return front == rear;
    }
    bool isFull()
    {
        return front == (rear + 1) % size;
    }
    void push(int element)
    {
        if (!isFull())
        {
            data[rear] = element;
            rear = (rear + 1) % size;
        }
        else
        {
            cout << "full" << endl;
        }
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "empty" << endl;
        }
        else
        {
            int ret = data[front];
            front = (front + 1) % size;
            return ret;
        }
        return -1;
    }
};

int main()
{
    RingQueue ringQueue(4);
    for (int i = 0; i < 5; i++)
    {
        ringQueue.push(i);
    }
    for (int i = 0; i < 5; i++)
    {
        cout << ringQueue.pop() << endl;
    }
}
#include <stack>
#include <limits.h>
#include <algorithm>
using namespace std;

class MinStack
{
private:
    stack<int> minStack;
    stack<int> stack;

public:
    /** initialize your data structure here. */
    MinStack()
    {
        minStack.push(INT_MAX);
    }

    void push(int x)
    {
        stack.push(x);
        minStack.push(min(minStack.top(), x));
    }

    void pop()
    {
        stack.pop();
        minStack.pop();
    }

    int top()
    {
        return stack.top();
    }

    int getMin()
    {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
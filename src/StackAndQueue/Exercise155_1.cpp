/* Note:not solved by myself */

#include <iostream>
#include <stack>
using namespace std;

class MinStack
{
private:
    stack<int> minimal, all;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        all.push(val);
        if (minimal.empty() || minimal.top() >= val)
            minimal.push(val);
    }

    void pop()
    {
        if (minimal.top() == all.top())
            minimal.pop();
        all.pop();
    }

    int top()
    {
        return all.top();
    }

    int getMin()
    {
        return minimal.top();
    }
};

int main()
{
    MinStack minstack;
    minstack.push(-2);
    minstack.push(-0);
    minstack.push(-3);
    cout << minstack.getMin();
    minstack.pop();
    minstack.top();
    cout << minstack.getMin();
}

/*Note:not solved by myself */
#include <iostream>
#include <stack>
using namespace std;

class MyQueue
{
private:
    stack<int> input;
    stack<int> output;

public:
    MyQueue()
    {

    }

    void push(int x)
    {
        input.push(x);
    }

    int pop()
    {
        peek();
        int val = output.top();
        output.pop();
        return val;
    }

    int peek()
    {
        if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }

    bool empty()
    {
        return output.empty() && input.empty();
    }
};
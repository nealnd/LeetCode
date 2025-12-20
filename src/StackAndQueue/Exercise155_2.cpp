
#include <iostream>
#include <vector>
using namespace std;

class MinStack
{
private:
    vector<vector<int>> st;

public:
    MinStack()
    {
    }

    void push(int val)
    {

        int minVal = st.empty() ? INT_MIN : getMin();
        if (st.empty() || minVal >= val)
        {
            minVal = val;
        }
        st.push_back({val, minVal});
    }

    void pop()
    {
        st.pop_back();
    }

    int top()
    {
        return st.back()[0];
    }

    int getMin()
    {
        return st.back()[1];
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

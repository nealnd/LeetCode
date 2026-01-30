#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        stack<int> st;
        for (int i = 0; i < temperatures.size(); i++)
        {
            while (!st.empty() && temperatures[st.top()] < temperatures[i])
            {
                temperatures[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }

        while (!st.empty())
        {

            temperatures[st.top()] = 0;
            st.pop();
        }
        return temperatures;
    }
};

int main()
{
    Solution sl;
    vector<int> temperatures{73, 74, 75, 71, 69, 72, 76, 73};
    sl.dailyTemperatures(temperatures);
}
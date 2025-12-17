#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    int calculate(string s)
    {
        s = "(" + s + ")";
        stack<string> st;
        string temp = "";
        for (auto c : s)
        {
            if (c == '(')
            {
                temp.push_back(c);
                st.push(temp);
                temp = "";
            }
            else if (isdigit(c))
            {
                temp.push_back(c);
            }
            else if (c == '+' || c == '-')
            {
                if (!temp.empty())
                {
                    st.push(temp);
                }
                else
                    st.push("0");
                temp = "";
                temp.push_back(c);
                st.push(temp);
                temp = "";
            }
            else if (c == ')')
            {
                stack<string> tempSt;
                if (!temp.empty())
                    st.push(temp);
                temp = "";
                while (st.top() != "(")
                {

                    string str = st.top();
                    tempSt.push(str);
                    st.pop();
                }
                while (tempSt.size() > 1)
                {
                    long long temp1 = stoll(tempSt.top());
                    tempSt.pop();
                    string sign = tempSt.top();
                    tempSt.pop();
                    long long temp2 = stoll(tempSt.top());
                    tempSt.pop();
                    if (sign == "+")
                    {
                        tempSt.push(to_string(temp1 + temp2));
                    }
                    else
                        tempSt.push(to_string(temp1 - temp2));
                }
                st.pop();
                temp = tempSt.top();
            }
        }
        return stoi(temp);
    }
};

int main()
{
    string s = "-2147483648";

    Solution sl;
    sl.calculate(s);
}
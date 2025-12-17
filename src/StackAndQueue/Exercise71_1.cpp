#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string simplifyPath(string path)
    {
        stack<char> st;
        st.push('/');
        path += "/";
        int count = 0;
        int lastIndex = 0;
        for (int i = 0; i < path.size(); i++)
        {
            if (path[i] == '/')
            {
                if (i - lastIndex == 2 && count == 1 && st.top() == '.')
                {
                    st.pop();
                }
                else if (i - lastIndex == 3 && count == 2 && st.top() == '.')
                {
                    while (st.top() != '/')
                        st.pop();
                    if (st.size() > 1)
                    {
                        st.pop();
                        while (st.top() != '/')
                            st.pop();
                    }
                }
                else if (st.top() == '/')
                {
                }
                else
                    st.push(path[i]);
                count = 0;
                lastIndex = i;
            }
            else if (path[i] == '.')
            {
                st.push(path[i]);
                count++;
            }
            else
            {
                st.push(path[i]);
                count = 0;
            }
        }
        if (st.top() == '/' && st.size() > 1)
            st.pop();
        string s;
        while (!st.empty())
        {
            s.push_back(st.top());
            st.pop();
        }
        reverse(s.begin(), s.end());
        return s;
    }
};

int main()
{
    string path = "/a//b////c/d//././/..";
    Solution sl;
    cout << sl.simplifyPath(path);
}
/* Note: getline is much better */

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Solution
{
public:
    string simplifyPath(string path)
    {
        stringstream ss(path);
        string token;
        vector<string> st;
        while (getline(ss, token, '/'))
        {
            if (token == "." || token == "")
                continue;
            if (token == "..")
            {
                if (!st.empty())
                    st.pop_back();
            }
            else
                st.push_back(token);
        }
        if (st.empty())
            return "/";
        string ans = "";
        for (auto it : st)
        {
            ans += "/" + it;
        }
        return ans;
    }
};

int main()
{
    string path = "/a//b////c/d//././/..";
    Solution sl;
    cout << sl.simplifyPath(path);
}
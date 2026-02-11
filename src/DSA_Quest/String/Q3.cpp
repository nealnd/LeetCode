#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string maskPII(string s)
    {
        string ans;
        if (s.find('@') != string::npos)
        {
            int index = s.find('@');
            ans += tolower(s[0]);
            ans += "*****";
            ans += tolower(s[index - 1]);
            ans += "@";
            for (int i = index + 1; i < s.size(); i++)
            {
                ans.push_back(tolower(s[i]));
            }
        }
        else
        {
            int count = 0;
            for (int i = s.size() - 1; i >= 0; i--)
            {

                if (s[i] == '+' || s[i] == '-' || s[i] == '(' || s[i] == ')' || s[i] == ' ')
                {
                    continue;
                }
                else
                {
                    if (ans.size() < 4)
                        ans.push_back(s[i]);
                    count++;
                }
            }
            if (count == 10)
            {
                ans += "-***-***";
            }
            else if (count == 11)
                ans += "-***-***-*+";
            else if (count == 12)
                ans += "-***-***-**+";
            else
                ans += "-***-***-***+";
            reverse(ans.begin(), ans.end());
        }
        return ans;
    }
};

int main()
{
    Solution sl;
    string s = "1(234)567-890";
    cout << sl.maskPII(s);
}
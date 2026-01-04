#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {

        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 1));
        string ans = s.substr(0, 1);

        for (int j = 0; j < s.size(); j++)
        {
            for (int i = 0; i < j; i++)
            {
                if (s[i] == s[j])
                {
                    if (i == j - 1 || dp[i + 1][j - 1] == j - i - 1)
                    {
                        dp[i][j] = j - i + 1;
                        if (j - i + 1 > ans.size())
                        {

                            ans = s.substr(i, j - i + 1);
                        }
                    }
                }
            }
        }

        return ans;
    }
}

;

int main()
{
    string s = "ccc";
    Solution sl;
    cout << sl.longestPalindrome(s);
}
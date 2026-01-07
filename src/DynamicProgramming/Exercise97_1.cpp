/* Note: not solved until seeing the hint */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        vector<vector<bool>> dp(s1.size() + 1, vector<bool>(s2.size() + 1));
        dp[0][0] = true;
        if (s3.size() != s1.size() + s2.size())
            return false;

        for (int i = 0; i <= s1.size(); i++)
        {
            for (int j = 0; j <= s2.size(); j++)
            {
                if (j >= 1 && dp[i][j - 1] && s2[j - 1] == s3[i + j - 1])
                    dp[i][j] = true;
                if (i >= 1 && dp[i - 1][j] && s1[i - 1] == s3[i + j - 1])
                    dp[i][j] = true;
            }
        }
        return dp[s1.size()][s2.size()];
    }
};

int main(){
    string s1("aabcc"), s2("dbbca"), s3("aadbbcbcac");
    Solution sl;
    cout << sl.isInterleave(s1, s2, s3);
}
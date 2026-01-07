/*Note: not solved by myself, when matrix[i][j] - '0' == 0, dp[i][j]=0   */

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        int maxCount = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 || j == 0 || matrix[i][j] - '0' == 0)
                {
                    dp[i][j] = matrix[i][j] - '0';
                }
                else
                {
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                }
                maxCount = max(maxCount, dp[i][j]);
            }
        }
        return maxCount * maxCount;
    }
};

int main()
{

    vector<vector<char>> matrix = {{'0', '1', '1', '0', '0', '1', '0', '1', '0', '1'}, {'0', '0', '1', '0', '1', '0', '1', '0', '1', '0'}, {'1', '0', '0', '0', '0', '1', '0', '1', '1', '0'}, {'0', '1', '1', '1', '1', '1', '1', '0', '1', '0'}, {'0', '0', '1', '1', '1', '1', '1', '1', '1', '0'}, {'1', '1', '0', '1', '0', '1', '1', '1', '1', '0'}, {'0', '0', '0', '1', '1', '0', '0', '0', '1', '0'}, {'1', '1', '0', '1', '1', '0', '0', '1', '1', '1'}, {'0', '1', '0', '1', '1', '0', '1', '0', '1', '1'}};
    Solution sol;
    cout << sol.maximalSquare(matrix) << endl;
}

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        dp[0][0] = (obstacleGrid[0][0] == 1 ? 0 : 1);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    continue;
                if (obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                else
                {

                    int way1 = i >= 1 ? dp[i - 1][j] : 0;
                    int way2 = j >= 1 ? dp[i][j - 1] : 0;
                    dp[i][j] = way1 + way2;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
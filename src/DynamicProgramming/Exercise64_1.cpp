#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        dp[0][0] = grid[0][0];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {

                if (i == 0 && j == 0)
                    continue;
                int sum1 = i >= 1 ? dp[i - 1][j] + grid[i][j] : INT_MAX;
                int sum2 = j >= 1 ? dp[i][j - 1] + grid[i][j] : INT_MAX;

                dp[i][j] = min(sum1, sum2);
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main()
{
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    Solution sl;
    cout << sl.minPathSum(grid);
}
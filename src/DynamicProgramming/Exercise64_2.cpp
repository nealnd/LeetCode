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
        vector<int> dp(n);
        dp[n - 1] = grid[m - 1][n - 1];
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (i == m - 1 && j == n - 1)
                    continue;
                int down = INT_MAX, right = INT_MAX;

                if (i < m - 1)
                    down = dp[j];
                if (j < m - 1)
                {
                    right = dp[j + 1];
                }
                dp[j] = min(right, down) + grid[i][j];
            }
        }
        return dp[0];
    }
};

int main()
{
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    Solution sl;
    cout << sl.minPathSum(grid);
}
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
        dp[0][0] = matrix[0][0] - '0';

        for (int i = 1; i < m; i++)
        {
            dp[i][0] = max(dp[i - 1][0], matrix[i][0] - '0');
        }

        for (int j = 1; j < n; j++)
        {
            dp[0][j] = max(dp[0][j - 1], matrix[0][j] - '0');
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] - '0' == 0)
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
                else
                {
                    int x = matrix[i - 1][j];
                    int y = matrix[i][j - 1];
                    int z = matrix[i - 1][j - 1];
                    int startI = i - 1, startJ = j - 1;
                    while (startI > i - 1 - z && startJ > j - 1 - z)
                    {
                        if (dp[startI][startJ] >= z - (i - startI) && matrix[i][startJ] - '0' == 1 && matrix[startI][j] - '0' == 1)
                        {
                            startI--;
                            startJ--;
                        }
                        else
                            break;
                    }
                    if (startI == i - 1 - z && startJ == j - 1 - z)
                    {
                        dp[i][j] = max(z + 1, max(dp[i - 1][j], dp[i][j - 1]));
                    }
                    else
                    {

                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    }
                }
            }
        }
        return dp[m - 1][n - 1] * dp[m - 1][n - 1];
    }
};
/* Note: a much better way, bottom up DP */
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int row = triangle.size();
        vector<int> memo = triangle[row - 1];

        for (int r = row - 2; r >= 0; r--)
        {
            for (int c = 0; c <= r; c++)
            {
                memo[c] = min(memo[c], memo[c + 1]) + triangle[r][c];
            }
        }

        return memo[0];
    }
};

/*

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = triangle.size() - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }
};

*/
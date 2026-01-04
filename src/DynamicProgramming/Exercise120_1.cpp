#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<int> dp(triangle[n - 1].size(), INT_MAX);
        dp[0] = triangle[0][0];
        // the number on top of current index
        int prev1 = dp[0];
        // the number before prev1
        int prev2 = INT_MAX;
        for (int i = 1; i < n; i++)
        {
            int m = triangle[i].size();
            for (int j = 0; j < m; j++)
            {

                int sum1 = (prev2 == INT_MAX ? INT_MAX : prev2 + triangle[i][j]);
                int sum2 = (prev1 == INT_MAX ? INT_MAX : prev1 + triangle[i][j]);
                prev2 = dp[j];
                if (j + 1 < m)
                {
                    prev1 = dp[j + 1];
                }
                else
                    prev1 = dp[0];

                dp[j] = min(sum1, sum2);
            }
        }

        return *std::min_element(dp.begin(), dp.end());
    }
};

int main()
{
    vector<vector<int>> triangle = {{-1}, {2, 3}, {1, -1, -3}};
    Solution sl;
    cout << sl.minimumTotal(triangle);
}
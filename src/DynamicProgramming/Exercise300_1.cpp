/* Note: not solved by myself, the parameter maxL is key */

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {

        vector<int> dp(nums.size(), 1);

        int maxL = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
                maxL = max(maxL, dp[i]);
            }
        }
        return maxL;
    }
};

int main()
{
    vector<int> nums{0, 1, 0, 3, 2, 3};
    Solution sl;
    cout << sl.lengthOfLIS(nums);
}
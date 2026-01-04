#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        vector<int> dp(nums.size() + 1, 0);
        dp[1] = nums[0];
        if (nums.size() == 1)
            return dp[1];
        dp[2] = nums[1] > nums[0] ? nums[1] : nums[0];
        for (int i = 3; i <= nums.size(); i++)
        {
            if (dp[i - 1] == dp[i - 2])
                dp[i] = dp[i - 2] + nums[i-1];
            else
                dp[i] = max(dp[i - 1], dp[i - 2] + nums[i-1]);
        }
        return dp[nums.size()];
    }
};

int main(){
    vector<int> nums{1, 2, 3, 1};
    Solution sl;
    cout << sl.rob(nums);
}
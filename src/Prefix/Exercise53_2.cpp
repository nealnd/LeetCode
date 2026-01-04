#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int maxSum = INT_MIN;
        int currentSum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            currentSum += nums[i];

            if (currentSum > maxSum)
            {
                maxSum = currentSum;
            }

            if (currentSum < 0)
            {
                currentSum = 0;
            }
        }

        return maxSum;
    }
};

int main()
{
    vector<int> nums = {-1, 0};
    Solution sl;
    sl.maxSubArray(nums);
}
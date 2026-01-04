#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            nums[i] = sum;
        }
        int minNum = 0, manxNum = INT_MIN;
        int maxSum = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > manxNum)
            {
                manxNum = nums[i];
                maxSum = max(maxSum, manxNum - minNum);
            }

            if (nums[i] <= minNum)
            {

                minNum = nums[i];
                maxSum = max(maxSum, nums[i] - (i >= 1 ? nums[i - 1] : 0));
                manxNum = nums[i];
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
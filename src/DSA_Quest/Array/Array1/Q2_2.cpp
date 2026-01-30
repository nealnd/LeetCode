#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> shuffle(vector<int> &nums, int n)
    {
        for (int i = 0; i < n; i++)
        {
            // 1 <= nums[i] <= 10^3
            nums[i] = (nums[i] << 10) | nums[i + n];
        }

        for (int i = n - 1; i >= 0; i--)
        {
            int y = nums[i] & ((1 << 10) - 1);
            int x = nums[i] >> 10;
            nums[2 * i] = x;
            nums[2 * i + 1] = y;
        }
        return nums;
    }
};
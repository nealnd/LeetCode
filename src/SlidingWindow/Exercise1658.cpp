#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int total = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            total += nums[i];
        }
        if (total < x)
            return -1;
        else if (total == x)
            return n;
        /*  a middle subarray whose sum is equal to the total sum minus x */
        int left = 0, currentTotal = 0, MaxMiddleLength = 0;
        for (int right = 0; right < n; right++)
        {
            currentTotal += nums[right];

            // slide condition:
            while (left <= right && currentTotal > total - x)
                currentTotal -= nums[left++];
            if (currentTotal == total - x)
                MaxMiddleLength = max(MaxMiddleLength, right - left + 1);
        }
        return MaxMiddleLength == 0 ? -1 : n - MaxMiddleLength;
    }
};

int main()
{
    vector<int> nums{3, 2, 20, 1, 1, 3};
    Solution sl;
    cout << sl.minOperations(nums, 10);
}
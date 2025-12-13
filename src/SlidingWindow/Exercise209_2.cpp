/* Note: O(nlogn) */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {

        int n = nums.size();
        int Sum = 0;
        int minRes = INT_MAX;
        vector<int> sums(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            sums[i] = sums[i - 1] + nums[i - 1];
        }

        for (int i = n; i >= 0 && sums[i] >= target; i--)
        {
            int j = upper_bound(sums.begin(), sums.end(), sums[i] - target) - sums.begin();
            minRes = min(minRes, i - j + 1);
        }

        return minRes == INT_MAX ? 0 : minRes;
    }
};
int main()
{
    int target = 11;
    vector<int> nums{1, 2, 3, 4, 5};
    Solution sl;
    cout << sl.minSubArrayLen(target, nums);
}
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        /* At any moment, the range [start, end] represents all indices that are reachable using the current number of jumps (step).
        When we decide to take one more jump, we scan every index in this range and compute how far we can reach with one additional jump.
        That farthest reachable position becomes the boundary of the next layer. */
        int n = nums.size(), step = 0, start = 0, end = 0;
        while (end < n - 1)
        {
            step++;
            int maxend = end + 1;
            for (int i = start; i <= end; i++)
            {
                if (i + nums[i] >= n - 1)
                    return step;
                maxend = max(maxend, i + nums[i]);
            }
            start = end + 1;
            end = maxend;
        }
        return step;
    }
};

int main()
{
    vector<int> nums{2, 3, 1, 1, 4};
    Solution sl;
    cout << sl.jump(nums);
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int goal = nums.size() - 1;
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if (i + nums[i] >= goal)
            {
                // update new goal
                goal = i;
            }
        }
        return goal == 0;
    }
};

int main()
{
    vector<int> nums{2, 3, 1, 1, 4};
    Solution sl;
    cout << sl.canJump(nums);
}
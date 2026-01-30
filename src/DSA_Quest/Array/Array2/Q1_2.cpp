/* Note: a better way */
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        int n = nums.size(), dup = -1, rem = -1;
        for (int num : nums)
        {
            int val = abs(num) - 1;
            if (nums[val] < 0)
                dup = abs(num);
            else
                nums[val] *= -1;
        }
        for (int i = 0; i < n; i++)
            if (nums[i] > 0)
                rem = i + 1;
        return {dup, rem};
    }
};

int main()
{
    vector<int> nums{1, 2, 2, 4};
    Solution sl;
    for (auto num : sl.findErrorNums(nums))
        cout << num << " ";
}
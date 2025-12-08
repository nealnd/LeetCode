#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n;
        vector<int> rotate(n);
        for (int i = 0; i < n; i++)
        {
            rotate[(i + k) % n] = nums[i];
        }

        for (int i = 0; i < n; i++)
        {
            nums[i] = rotate[i];
        }
    }
};

int main()
{
    vector<int> nums{1, 2, 3, 4, 5, 6, 7};
    Solution sl;
    sl.rotate(nums, 3);
    for (auto num : nums)
    {
        cout << num << " ";
    }
}
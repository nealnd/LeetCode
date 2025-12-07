#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int i = 0;
        for (auto num : nums)
        {
            if (i == 0 || i == 1 || nums[i - 2] != num)
            {
                nums[i] = num;
                i++;
            }
        }
        return i;
    }
};

int main()
{
    vector<int> nums{0, 0, 1, 1, 1, 1, 2, 3, 3};
    Solution sl;
    cout << sl.removeDuplicates(nums) << endl;
}
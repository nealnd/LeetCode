#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int count = 0;
        int j = 0;
        int n = nums.size();
        for (int i = 0; i < n - j; i++)
        {
            if (nums[i] == val)
            {
                if (nums[n - 1 - j] != val)
                {
                    swap(nums[i], nums[n - 1 - j]);
                }

                j++;
                i--;
            }
            else
                count++;
        }
        return count;
    }
};

int main()
{
    vector<int> nums{0, 1, 2, 2, 3, 0, 4, 2};
    Solution sl;
    cout << sl.removeElement(nums, 2);
}
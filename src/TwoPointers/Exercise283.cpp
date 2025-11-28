#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return;
        else
        {
            int i = 0, j = 1;
            int n = nums.size();
            while (i < n && j < n)
            {
                if ((nums[i] == 0 && nums[j] != 0))
                {
                    swap(nums[i], nums[j]);
                    i++;
                    j++;
                }
                else if (nums[i] == 0 && nums[j] == 0)
                {
                    j++;
                }
                else
                {
                    j++;
                    i++;
                }
            }
        }
    }
};

int main(){
    vector<int> nums{0, 1, 0, 3, 12};
    Solution s;
    s.moveZeroes(nums);
    for(auto num:nums)
        cout << num << endl;
}
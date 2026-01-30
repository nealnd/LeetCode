#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        for (auto num : nums)
        {
            int i = abs(num) - 1;
            if (nums[i] > 0)
                nums[i] *= -1;
        }
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                result.push_back(i + 1);
            }
        }
        return result;
    }
};

int main(){
    vector<int> nums{4, 3, 2, 7, 8, 2, 3, 1};
    Solution sl;
    for(auto ans:sl.findDisappearedNumbers(nums))
        cout << ans << " ";
}
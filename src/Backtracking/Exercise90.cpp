#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        subsetsWithDup(nums, 0, ans, temp);
        return ans;
    }

private:
    void subsetsWithDup(vector<int> &nums, int start, vector<vector<int>> &ans, vector<int> &temp)
    {
        ans.push_back(temp);
        for (int i = start; i < nums.size(); i++)
        {
            if (i > start && nums[i] == nums[i - 1])
                continue;
            temp.push_back(nums[i]);
            subsetsWithDup(nums, i + 1, ans, temp);
            temp.pop_back();
        }
    }
};

int main()
{
    vector<int> nums{1, 2, 2};
    Solution sl;
    sl.subsetsWithDup(nums);
}
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        subsetsHelper(nums, 0, ans, temp);
        return ans;
    }

private:
    void subsetsHelper(vector<int> &nums, int left, vector<vector<int>> &ans, vector<int> &temp)
    {

        ans.push_back(temp);

        for (int i = left; i < nums.size(); i++)
        {
            temp.push_back(nums[i]);
            subsetsHelper(nums, i + 1, ans, temp);
            temp.pop_back();
        }
    }
};

int main()
{
    vector<int> nums{1, 2, 3};
    Solution sl;
    sl.subsets(nums);
}
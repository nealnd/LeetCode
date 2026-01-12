#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<bool> visited(nums.size(), false);
        sort(nums.begin(), nums.end());
        vector<int> temp;
        permuteUnique(nums, ans, temp, visited);
        return ans;
    }

private:
    void permuteUnique(vector<int> &nums, vector<vector<int>> &ans, vector<int> &temp, vector<bool> &visited)
    {
        if (temp.size() == nums.size())
        {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (i < nums.size() - 1 && !visited[i] && visited[i + 1] && nums[i] == nums[i + 1])
                continue;
            if (visited[i])
                continue;
            temp.push_back(nums[i]);
            visited[i] = true;
            permuteUnique(nums, ans, temp, visited);
            visited[i] = false;
            temp.pop_back();
        }
    }
};

int main()
{
    vector<int> nums{1, 1, 2};
    Solution sl;
    sl.permuteUnique(nums);
}
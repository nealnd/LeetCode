#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> visited(nums.size(), false);
        premute(nums, ans, temp, visited);
        return ans;
    }

private:
    void premute(vector<int> &nums, vector<vector<int>> &ans, vector<int> &temp, vector<bool> &visited)
    {

        if (temp.size() == nums.size())
        {
            ans.push_back(vector<int>(temp.begin(), temp.end()));

            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (visited[i])
                continue;
            visited[i] = true;
            temp.push_back(nums[i]);
            premute(nums, ans, temp, visited);
            temp.pop_back();
            visited[i] = false;
        }
    }
};

int main()
{
    vector<int> nums{6, 2, -1, 8};
    Solution sl;
    sl.permute(nums);
}
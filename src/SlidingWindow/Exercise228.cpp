#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {

        int n = nums.size();
        vector<string> res;
        if (nums.empty())
            return res;
        int start = nums[0];
        for (int end = 1; end <= n; end++)
        {
            if (end == n || nums[end] != nums[end - 1] + 1)
            {
                if (start == nums[end - 1])
                    res.push_back(to_string(start));
                else
                    res.push_back(to_string(start) + "->" + to_string(nums[end - 1]));
                if (end < n)
                    start = nums[end];
            }
        }
        return res;
    }
};

int main()
{
    vector<int> nums{0, 1, 2, 4, 5, 7};
    Solution sl;
    for (auto &s : sl.summaryRanges(nums))
        cout << s << " ";
}
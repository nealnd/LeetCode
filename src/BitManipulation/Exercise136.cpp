#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;
        for (auto num : nums)
        {
            ans = ans ^ num;
        }
        return ans;
    }
};

int main()
{
    vector<int> nums {4, 1, 2, 1, 2};
    Solution sl;
    cout << sl.singleNumber(nums);
}
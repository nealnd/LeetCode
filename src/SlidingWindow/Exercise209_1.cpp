#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int i = 0;
        int n = nums.size();
        int Sum = 0;
        int minRes = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            Sum += nums[j];
            if (Sum >= target)
            {

                while (Sum >= target && i <= j)
                {

                    Sum -= nums[i];
                    i++;
                }
                minRes = min(minRes, j - i + 2);
            }
        }
        return minRes == INT_MAX ? 0 : minRes;
    }
};

int main()
{
    int target = 11;
    vector<int> nums{1, 2, 3, 4, 5};
    Solution sl;
    cout << sl.minSubArrayLen(target, nums);
}
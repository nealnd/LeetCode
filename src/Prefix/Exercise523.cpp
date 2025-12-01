/* Note:not solved by myself */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> Sum;
        int totalSum = 0;
        Sum[0] = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            totalSum += nums[i];
            if (Sum.contains(totalSum % k))
            {
                if (i - Sum[totalSum % k] >= 2)
                    return true;
            }
            else
                Sum[totalSum % k] = i;
        }
        return false;
    }
};

int main()
{
    vector<int> nums{23, 2, 6, 4, 7};
    Solution sl;
    cout << sl.checkSubarraySum(nums, 13);
}

/* NOTE: not solved by myself,  place the map in the loop */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> subSum;
        int TotalSum = 0;
        int count = 0;
        subSum[0] = 1;
        for (int i = 0; i < nums.size(); i++)
        {

            TotalSum += nums[i];
            if (subSum.contains(TotalSum - k))
            {
                count += subSum[TotalSum - k];
            }
            subSum[TotalSum]++;
        }
        return count;
    }
};

int main()
{
    vector<int> nums{1, 2, 1, 2, 1};
    Solution sl;
    cout << sl.subarraySum(nums, 3);
}
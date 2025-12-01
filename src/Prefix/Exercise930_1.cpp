/* Note:the other medthod--sliding window */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {

        int total = 0;
        unordered_map<int, int> prefixSum;
        prefixSum[0] = 1;
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            total += nums[i];
            if (prefixSum.contains(total - goal))
            {
                count += prefixSum[total - goal];
            }
            prefixSum[total]++;
        }
        return count;
    }
};

int main()
{
    vector<int> nums{1, 0, 1, 0, 1};
    Solution sl;
    cout << sl.numSubarraysWithSum(nums, 2);
}
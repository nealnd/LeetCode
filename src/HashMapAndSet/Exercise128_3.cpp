/* Note: a better method, really awesome, imagine each number as its own “island */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        int maxLen = 0;
        for (int num : nums)
        {
            if (!mp[num])
            {
                mp[num] = mp[num - 1] + mp[num + 1] + 1;
                mp[num - mp[num - 1]] = mp[num];
                mp[num + mp[num + 1]] = mp[num];
                maxLen = max(maxLen, mp[num]);
            }
        }
        return maxLen;
    }
};

int main()
{
    vector<int> nums{0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    Solution sl;
    cout << sl.longestConsecutive(nums);
}
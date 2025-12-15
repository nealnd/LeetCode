#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            if (map.contains(nums[i]))
            {
                if (i - map[nums[i]] <= k)
                    return true;
            }
            map[nums[i]] = i;
        }
        return false;
    }
};

int main()
{
    vector<int> nums{1, 2, 3, 1, 2, 3};
    int k = 2;
    Solution sl;
    cout << sl.containsNearbyDuplicate(nums, k);
}
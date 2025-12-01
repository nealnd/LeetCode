/* Note: not solved by myself, didn't come up with: if (prefixMod < 0)
                prefixMod += k; */

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        int prefixMod = 0;
        unordered_map<int, int> Sum;
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            prefixMod += nums[i];
            prefixMod %= k;
            if (prefixMod < 0)
                prefixMod += k;
            if (prefixMod == 0)
                count++;
            if (Sum.contains(prefixMod))
            {
                count += Sum[prefixMod];
            }
            Sum[prefixMod]++;
        }
        return count;
    }
};

int main()
{
    vector<int> nums{4, 5, 0, -2, -3, 1};
    Solution sl;
    cout << sl.subarraysDivByK(nums, 5) << endl;
}
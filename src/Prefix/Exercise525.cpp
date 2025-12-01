#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        unordered_map<int, int> prefix;
        prefix[0] = 0;
        int total = 0;
        int MaxLength = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            total += nums[i];
            if (prefix.contains(2 * total - i - 1))
            {
                MaxLength = max(MaxLength, i + 1 - prefix[2 * total - i - 1]);
            }
            else
                prefix[2 * total - (i + 1)] = i + 1;
        }
        return MaxLength;
    }
};

int main()
{
    vector<int> nums{0, 1, 1, 1, 1, 1, 0, 0, 0};
    Solution sl;
    cout << sl.findMaxLength(nums);
}
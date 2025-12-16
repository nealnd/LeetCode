#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return nums.size();
        unordered_set<int> set;
        for (auto num : nums)
        {
            set.insert(num);
        }

        int maxLength = 0;

        while (!set.empty())
        {
            int num = *set.begin();
            set.erase(num);

            int length = 1;

            int lower = num - 1;
            while (!set.empty() && set.contains(lower))
            {
                set.erase(lower);
                lower--;
                length++;
            }

            int upper = num + 1;
            while (!set.empty() && set.contains(upper))
            {
                set.erase(upper);
                upper++;
                length++;
            }

            maxLength = max(maxLength, length);
        }
        return maxLength;
    }
};

int main()
{
    vector<int> nums{0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    Solution sl;
    cout << sl.longestConsecutive(nums);
}
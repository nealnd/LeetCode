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
        unordered_set<int> set(nums.begin(), nums.end());
        int maxLength = 0;

        for (int num : set)
        {

            if (!set.contains(num - 1))
            {
                int current = num;
                int length = 1;

                while (set.contains(current + 1))
                {
                    current++;
                    length++;
                }

                maxLength = max(maxLength, length);
            }
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
#include <iostream>
#include <vector>
#include <unordered_set>

class Solution
{
public:
    bool containsNearbyDuplicate(std::vector<int> &nums, int k)
    {
        std::unordered_set<int> set;

        for (int i = 0; i < nums.size(); ++i)
        {
            // Remove the element that is now outside the window
            if (i > k)
            {
                set.erase(nums[i - k - 1]);
            }

            // Check if the current element exists in the set
            if (set.contains(nums[i]))
            {
                return true;
            }

            // Add the current element to the set
            set.insert(nums[i]);
        }

        return false;
    }
};

int main()
{
    std::vector<int> nums{1, 2, 3, 1, 2, 3};
    int k = 2;
    Solution sl;
    std::cout << sl.containsNearbyDuplicate(nums, k);
}
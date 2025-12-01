/* Note: not solved by myself, prefixZeros is genius */

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        int left = 0;
        int prefixZeros = 0;
        int currentSum = 0;
        int totalCount = 0;

        // Loop through the array using end pointer
        for (int right = 0; right < nums.size(); right++)
        {
            // Add current element to the sum
            currentSum += nums[right];

            // Slide the window while condition is met
            while (left < right && (nums[left] == 0 || currentSum > goal))
            {
                if (nums[left] == 1)
                {
                    prefixZeros = 0;
                }
                else
                {
                    prefixZeros += 1;
                }

                currentSum -= nums[left];
                left += 1;
            }

            // Count subarrays when window sum matches the goal
            if (currentSum == goal)
            {
                totalCount += 1 + prefixZeros;
            }
        }

        return totalCount;
    }
};

int main()
{
    vector<int> nums{1, 0, 1, 0, 1};
    Solution sl;
    cout << sl.numSubarraysWithSum(nums, 2);
}
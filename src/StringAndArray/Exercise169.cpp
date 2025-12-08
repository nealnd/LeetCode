/* Note:not solved, this is Boyer-Moore Majority Voting Algorithm */

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int vote = 0, candidate = -1;
        for (auto num : nums)
        {
            if (vote == 0)
            {
                // update the candidate
                candidate = num;
                vote++;
            }
            else
            {
                if (candidate == num)
                {
                    vote++;
                }
                else
                    vote--;
            }
        }
        return candidate;
    }
};

int main()
{
    vector<int> nums{2, 2, 1, 1, 1, 2, 2};
    Solution sl;
    cout << sl.majorityElement(nums);
}
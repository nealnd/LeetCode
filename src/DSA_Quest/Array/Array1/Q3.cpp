#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int i = -1;
        int maxCount = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] == 0)
            {
                i = j;
            }
            else{
                maxCount = max(j - i, maxCount);
            }
        }
        return maxCount;
    }
};

int main(){
    vector<int> nums{1, 1, 0, 1, 1, 1};
    Solution sl;
    cout << sl.findMaxConsecutiveOnes(nums);
}
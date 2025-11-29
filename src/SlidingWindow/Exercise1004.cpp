#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int n = nums.size();
        int maxCount = 0;
        int left = 0, right = 0;
        int count=0;
        while(right<n){
            if(nums[right]==0){
                count++;
            }
            while(count>k){
                if(nums[left]==0){
                    count--;
                }
                left++;
            }
            maxCount = max(maxCount, right - left + 1);
            right++;
        }

        return maxCount;
    }
};

int main()
{
    vector<int> nums{1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    Solution sl;
    cout << sl.longestOnes(nums, 2);
}
#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        vector<int> arr(nums.size(), 0);
        int wrongNum = 0, originalNum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            arr[nums[i] - 1]++;
            if (arr[nums[i] - 1] > 1)
            {
                wrongNum = nums[i];
            }
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (arr[i] == 0)
            {
                originalNum = i + 1;
                break;
            }
        }
        return vector<int>{wrongNum, originalNum};
    }
};

int main(){
    vector<int> nums{1, 2, 2, 4};
    Solution sl;
    for(auto num:sl.findErrorNums(nums))
        cout << num << " ";
}
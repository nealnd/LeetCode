#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int totalSum = 0;
        for (int i = 0; i < nums.size();i++){
            totalSum += nums[i];
        }

        int leftSum = 0;
        for (int i = 0; i < nums.size();i++){
            if(leftSum==totalSum-nums[i]-leftSum)
                return i;
            leftSum += nums[i];
        }
        return -1;
    }
};

int main(){
    vector<int> nums{2, 1, -1};
    Solution sl;
    cout << sl.pivotIndex(nums);
}
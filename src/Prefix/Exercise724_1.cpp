#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        vector<int> prefix(nums.size(), 0);
        vector<int>suffix(nums.size(),0);
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            prefix[i] += sum;
            sum += nums[i];
        }
        sum = 0;
        for (int i = nums.size() - 1;i>=0; i--)
        {
            suffix[i] += sum;
            sum += nums[i];
        }

        for (int i = 0; i < nums.size();i++){
            if(prefix[i]==suffix[i])
                return i;
        }
        return -1;
    }
};

int main(){
    vector<int> nums{2, 1, -1};
    Solution sl;
    cout << sl.pivotIndex(nums);
}

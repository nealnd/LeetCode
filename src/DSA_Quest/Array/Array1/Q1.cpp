#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    vector<int> getConcatenation(vector<int> &nums)
    {
        vector<int> ans(nums.begin(), nums.end());
        for(auto num:nums){
            ans.push_back(num);
        }
        return ans;
    }
};

int main(){
    vector<int> nums{1, 2, 3};
    Solution sl;
    for (auto num : sl.getConcatenation(nums)){
        cout << num << " ";
    }
}
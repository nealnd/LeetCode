#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int left = 0, right = 0;
        int maxNum = 0;
        int count = 0;
        for (; right < nums.size();right++){
            if(nums[right]==0){
                count++;
            }
            if(count>1){
                if(nums[left]==0) {
                    count--;
                }
                left++;
            }
            maxNum = max(maxNum, right - left);
        }
        return maxNum;
    }
};

int main(){
    vector<int> nums{0, 1, 1, 1, 0, 1, 1, 0, 1};
    Solution sl;
    cout << sl.longestSubarray(nums);
}
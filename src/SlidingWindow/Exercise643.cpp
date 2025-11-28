#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        long long sum = 0;
        int n = nums.size();
        //k<=n
        for (int i = 0; i < k;i++){
            sum += nums[i];
        }
        double average = (double)sum / k;

        for (int j = k; j < n;j++){
            sum -= nums[j - k];
            sum += nums[j];
            average = max(average, (double)sum / k);
        }
        return average;
    }
};

int main(){
    vector<int> nums{4, 0, 4, 3, 3};
    Solution sl;
    cout << sl.findMaxAverage(nums, 5);
}
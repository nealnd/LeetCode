#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, 1);

        // prefix
        int current = 1;
        for (int i = 0; i < n; i++)
        {
            ans[i] *= current;
            current *= nums[i];
        }

        current = 1;
        // suffix
        for (int i = n - 1; i >= 0; i--)
        {
            ans[i] *= current;
            current *= nums[i];
        }
        return ans;
    }
};

int main(){
    vector<int> nums{1, 2, 3, 4};
    Solution sl;
    for(auto ans:sl.productExceptSelf(nums)){
        cout << ans << endl;
    }
}
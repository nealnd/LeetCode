#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> Prefix(n);
        vector<int> Suffix(n);
        Prefix[0] = 1;
        Suffix[n - 1] = 1;
        // prefix
        for (int i = 1; i < n; i++)
        {
            Prefix[i] = Prefix[i - 1] * nums[i - 1];
        }
        // suffix
        for (int i = n - 2; i >= 0; i--)
        {
            Suffix[i] = Suffix[i + 1] * nums[i + 1];
        }

        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            ans[i] = Prefix[i] * Suffix[i];
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
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n;
        if (k != 0)
        {
            vector<int> temp(nums.end() - k, nums.end());
            temp.insert(temp.end(), nums.begin(), nums.end() - k);
            copy(temp.begin(), temp.end(), nums.begin());
        }
    }
};

int main()
{
    vector<int> nums{1, 2, 3, 4, 5, 6, 7};
    Solution sl;
    sl.rotate(nums, 3);
    for (auto num : nums)
    {
        cout << num << " ";
    }
}
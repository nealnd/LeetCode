#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {
        vector<int> vec(101, 0);
        for (auto num : nums)
        {
            vec[num]++;
        }
        int count = 0;
        for (int i = 0; i < vec.size(); i++)
        {
            count += vec[i];
            vec[i] = count;
        }
        vector<int> result;
        for (auto num : nums)
        {
            if (num > 0)
                result.push_back(vec[num - 1]);
            else
                result.push_back(0);
        }
        return result;
    }
};

int main(){
    vector<int> nums{8, 1, 2, 2, 3};
    Solution sl;
    for(auto ans:sl.smallerNumbersThanCurrent(nums))
        cout << ans << " ";
}
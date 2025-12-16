#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int n = citations.size();
        vector<int> nums(n + 1, 0);
        int res = 0;
        for (auto citation : citations)
        {
            if (citation >= n)
            {
                nums[n]++;
            }
            else
                nums[citation]++;
        }

        int count = 0;
        for (int i = n; i >= 0; i--)
        {
            count += nums[i];
            if (count >= i)
            {

                res = i;
                break;
            }
        }
        return res;
    }
};

int main()
{
    vector<int> citations{3, 0, 6, 1, 5};
    Solution sl;
    cout << sl.hIndex(citations);
}
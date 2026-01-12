#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {

        for (int i = 1; i <= n - k + 1; i++)
        {
            vector<int> temp;
            helper(n, i, k, temp);
        }
        return ans;
    }

private:
    vector<vector<int>> ans;
    void helper(int n, int start, int k, vector<int> &temp)
    {
        temp.push_back(start);
        k--;
        if (k == 0)
        {
            ans.push_back(temp);
            return;
        }
        else
        {

            for (int i = start + 1; i <= n + 1 - k; i++)
            {
                helper(n, i, k, temp);
                temp.pop_back();
            }
        }
    }
};

int main()
{
    Solution sl;
    int n = 4, k = 2;
    sl.combine(n, k);
}
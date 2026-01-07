#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ans;
    }

private:
    vector<vector<int>> ans;
    void helper(int n, int start, int k, vector<int> &temp)
    {

        if (k == 1)
        {
            ans.push_back(temp);
            return;
        }

        temp.push_back(start);

        for (int i = start + 1; i <= n; i++)
        {
            helper(n, start + 1, k - 1, temp);
        }
    }
};
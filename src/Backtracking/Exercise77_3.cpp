#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ans;
        vector<int> temp(k);
        helper(n, k, 1, temp, ans);
        return ans;
    }

private:
    void helper(int n, int k, int start, vector<int> &temp, vector<vector<int>> &ans)
    {
        if (k == 0)
        {
            ans.push_back(temp);
            return;
        }
        for (int i = start; i <= n; i++)
        {
            temp[temp.size() - k] = i;
            helper(n, k - 1, i + 1, temp, ans);
        }
    }
};

int main()
{
    Solution sl;
    int n = 4, k = 2;
    for (auto vec : sl.combine(n, k))
    {
        for (auto v : vec)
            cout << v << " ";
        cout << endl;
    }
}
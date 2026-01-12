#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<bool> col(n, false);
        vector<bool> diag1(2 * n - 1, false);
        vector<bool> diag2(2 * n - 1, false);

        vector<vector<string>> ans;
        vector<string> temp;
        NQueensHelper(n, 0, col, diag1, diag2, ans, temp);
        return ans;
    }

private:
    void NQueensHelper(int n, int row, vector<bool> &col, vector<bool> &diag1, vector<bool> &diag2, vector<vector<string>> &ans, vector<string> &temp)
    {
        if (row == n)
        {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < n; i++)
        {
            int d1 = row - i + n - 1;
            int d2 = row + i;
            if (col[i] || diag1[d1] || diag2[d2])
                continue;
            temp.push_back(string(i, '.') + "Q" + string(n - 1 - i, '.'));
            col[i] = diag1[d1] = diag2[d2] = true;
            NQueensHelper(n, row + 1, col, diag1, diag2, ans, temp);
            col[i] = diag1[d1] = diag2[d2] = false;
            temp.pop_back();
        }
    }
};

int main()
{
    int n = 5;
    Solution sl;
    sl.solveNQueens(n);
}
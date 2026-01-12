/* Note: a much better way: three boolean arrays to track occupied columns and diagonals */
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int totalNQueens(int n)
    {
        vector<bool> col(n, false);
        vector<bool> diag1(2 * n - 1, false); // i - j + (n - 1)
        vector<bool> diag2(2 * n - 1, false); // i + j

        int ans = 0;
        backtrack(0, n, col, diag1, diag2, ans);
        return ans;
    }

private:
    void backtrack(
        int row,
        int n,
        vector<bool> &col,
        vector<bool> &diag1,
        vector<bool> &diag2,
        int &ans)
    {
        if (row == n)
        {
            ans++;
            return;
        }

        for (int j = 0; j < n; j++)
        {
            int d1 = row - j + (n - 1);
            int d2 = row + j;

            if (col[j] || diag1[d1] || diag2[d2])
                continue;

            col[j] = diag1[d1] = diag2[d2] = true;
            backtrack(row + 1, n, col, diag1, diag2, ans);
            col[j] = diag1[d1] = diag2[d2] = false;
        }
    }
};

int main()
{
    int n = 5;
    Solution sl;
    cout << sl.totalNQueens(n);
}
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int totalNQueens(int n)
    {
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        int ans = 0;
        for (int j = 0; j < n; j++)
        {
            int ways = 0;
            if (NQueensHelper(n, 0, j, visited, 0, ways))
            {
                ans += ways;
            }
        }
        return ans;
    }

private:
    bool NQueensHelper(int n, int indexI, int indexJ, vector<vector<bool>> visited, int counts, int &ways)
    {
        if (counts == n - 1)
        {
            ways++;
            return true;
        }

        visited[indexI][indexJ] = true;
        for (int i = 0; i < n; i++)
        {
            visited[indexI][i] = true;
            visited[i][indexJ] = true;
            if (indexI - i >= 0 && indexJ - i >= 0)
                visited[indexI - i][indexJ - i] = true;
            if (indexI + i < n && indexJ + i < n)
                visited[indexI + i][indexJ + i] = true;
            if (indexI + i < n && indexJ - i >= 0)
                visited[indexI + i][indexJ - i] = true;
            if (indexI - i >= 0 && indexJ + i < n)
                visited[indexI - i][indexJ + i] = true;
        }
        bool bFound = false;

        for (int j = 0; j < n; j++)
        {

            if (visited[indexI + 1][j])
                continue;
            if (NQueensHelper(n, indexI + 1, j, visited, counts + 1, ways))
            {
                bFound = true;
            }
        }

        return bFound;
    }
};

int main()
{
    int n = 12;
    Solution sl;
    cout << sl.totalNQueens(n);
}
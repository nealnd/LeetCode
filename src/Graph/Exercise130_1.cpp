#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void solve(vector<vector<char>> &board)
    {
        // board is not empty;
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++)
        {
            if (board[i][0] == 'O' && visited[i][0] == false)
            {
                dfs(board, visited, i, 0);
            }
            if (board[i][n - 1] == 'O' && visited[i][n - 1] == false)
                dfs(board, visited, i, n - 1);
        }
        for (int i = 0; i < n; i++)
        {
            if (board[0][i] == 'O' && visited[0][i] == false)
            {
                dfs(board, visited, 0, i);
            }
            if (board[m - 1][i] == 'O' && visited[m - 1][i] == false)
            {
                dfs(board, visited, m - 1, i);
            }
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (board[i][j] == 'O' && visited[i][j] == false)
                {
                    board[i][j] = 'X';
                }
            }
        }
    }

private:
    void dfs(vector<vector<char>> &board, vector<vector<bool>> &visited, int i, int j)
    {
        int m = board.size();
        int n = board[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n || visited[i][j] == true || board[i][j] == 'X')
        {
            return;
        }
        visited[i][j] = true;
        dfs(board, visited, i + 1, j);
        dfs(board, visited, i - 1, j);
        dfs(board, visited, i, j - 1);
        dfs(board, visited, i, j + 1);
    }
};

int main()
{
    vector<vector<char>> board{{'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}};
    Solution sl;
    sl.solve(board);
    for (auto bo : board)
    {
        for (auto b : bo)
        {
            cout << b << " ";
        }
        cout << endl;
    }
}
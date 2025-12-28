#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void solve(vector<vector<char>> &board)
    {

        for (int i = 0; i < board[0].size(); i++)
        { // Check first row
            if (board[0][i] == 'O')
                setSign(0, i, board);
        }
        for (int i = 0; i < board[0].size(); i++)
        { // Check last row
            if (board[board.size() - 1][i] == 'O')
                setSign(board.size() - 1, i, board);
        }
        for (int i = 0; i < board.size(); i++)
        { // Check first column
            if (board[i][0] == 'O')
                setSign(i, 0, board);
        }
        for (int i = 0; i < board.size(); i++)
        { // Check last column
            if (board[i][board[0].size() - 1] == 'O')
                setSign(i, board[0].size() - 1, board);
        }

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == '-')
                    board[i][j] = 'O';
            }
        }
    }

    void setSign(int i, int j, vector<vector<char>> &board)
    {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != 'O')
            return;
        board[i][j] = '-';
        setSign(i + 1, j, board);
        setSign(i - 1, j, board);
        setSign(i, j + 1, board);
        setSign(i, j - 1, board);
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
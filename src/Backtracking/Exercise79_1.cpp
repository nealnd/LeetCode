#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        string temp;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (existHelper(board, word, temp, visited, i, j))
                    return true;
            }
        }
        return false;
    }

private:
    bool existHelper(vector<vector<char>> &board, string &word, string &temp, vector<vector<bool>> &visited, int i, int j)
    {
        temp.push_back(board[i][j]);
        visited[i][j] = true;

        if (temp != word.substr(0, temp.size()))
        {
            temp.pop_back();
            visited[i][j] = false;
            return false;
        }

        if (temp.size() == word.size())
        {
            return true;
        }

        bool found = false;

        if (i > 0 && !visited[i - 1][j])
            found = existHelper(board, word, temp, visited, i - 1, j);

        if (!found && j > 0 && !visited[i][j - 1])
            found = existHelper(board, word, temp, visited, i, j - 1);

        if (!found && i < board.size() - 1 && !visited[i + 1][j])
            found = existHelper(board, word, temp, visited, i + 1, j);

        if (!found && j < board[0].size() - 1 && !visited[i][j + 1])
            found = existHelper(board, word, temp, visited, i, j + 1);

        temp.pop_back();
        visited[i][j] = false;

        return found;
    }
};

int main()
{
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string word("ABCB");
    Solution sl;
    cout << sl.exist(board, word);
}
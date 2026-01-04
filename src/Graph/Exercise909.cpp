/* Note: spend a lot of time to solve this question */
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
    int snakesAndLadders(vector<vector<int>> &board)
    {
        int m = board.size();
        int count = 0;

        queue<int> q;
        vector<bool> visited(m * m + 1, false);

        q.push(1);
        visited[1] = true;

        while (!q.empty())
        {
            int n = q.size();
            count++;

            for (int i = 0; i < n; i++)
            {
                int startIndex = q.front();
                q.pop();

                for (int j = 1; j <= 6; j++)
                {
                    int next = startIndex + j;
                    if (next > m * m)
                        continue;

                    auto [row, col] = IndexToCoordinate(next, m);

                    if (board[row][col] != -1)
                        next = board[row][col];

                    if (next == m * m)
                        return count;

                    if (!visited[next])
                    {
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }
        }
        return -1;
    }

private:
    pair<int, int> IndexToCoordinate(int index, int m)
    {
        int row = m - 1 - (index - 1) / m;
        int col = (m - row) % 2 == 1
                      ? (index - 1) % m
                      : m - 1 - (index - 1) % m;
        return {row, col};
    }
};

int main()
{
    vector<vector<int>> board = {{-1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1}, {-1, 35, -1, -1, 13, -1}, {-1, -1, -1, -1, -1, -1}, {-1, 15, -1, -1, -1, -1}};

    Solution sl;
    cout << sl.snakesAndLadders(board);
}

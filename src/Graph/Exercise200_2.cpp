#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int count = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {

                if (grid[i][j] == '1')
                {
                    count++;
                    grid[i][j] = '0';
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while (!q.empty())
                    {
                        pair<int, int> node = q.front();
                        q.pop();
                        int x = node.first, y = node.second;
                        if (x + 1 < grid.size() && grid[x + 1][y] == '1')
                        {
                            grid[x + 1][y] = '0';
                            q.push({x + 1, y});
                        }
                        if (x - 1 >= 0 && grid[x - 1][y] == '1')
                        {
                            grid[x - 1][y] = '0';
                            q.push({x - 1, y});
                        }

                        if (y + 1 < grid[0].size() && grid[x][y + 1] == '1')
                        {
                            grid[x][y + 1] = '0';
                            q.push({x, y + 1});
                        }
                        if (y - 1 >= 0 && grid[x][y - 1] == '1')
                        {
                            grid[x][y - 1] = '0';
                            q.push({x, y - 1});
                        }
                    }
                }
            }
        }
        return count;
    }
};

int main()
{
    vector<vector<char>> grid{{'1', '1', '1', '1', '0'}, {'1', '1', '0', '1', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '0', '0', '0'}};
    Solution sl;
    cout << sl.numIslands(grid);
}
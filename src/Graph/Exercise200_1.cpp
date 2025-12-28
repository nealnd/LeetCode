#include <iostream>
#include <vector>
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
                    Depth(grid, i, j);
                }
            }
        }
        return count;
    }

private:
    void Depth(vector<vector<char>> &grid, int i, int j)
    {
        if (grid[i][j] == '0')
            return;

        else
        {

            grid[i][j] = '0';
            if (i + 1 < grid.size())
                Depth(grid, i + 1, j);
            if (i - 1 >= 0)
                Depth(grid, i - 1, j);
            if (j + 1 < grid[0].size())
                Depth(grid, i, j + 1);
            if (j - 1 >= 0)
                Depth(grid, i, j - 1);
        }
    }
};

int main()
{
    vector<vector<char>> grid{{'1', '1', '1', '1', '0'}, {'1', '1', '0', '1', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '0', '0', '0'}};
    Solution sl;
    cout << sl.numIslands(grid);
}
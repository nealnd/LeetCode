#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] < b[0]; });

        int count = 1;
        int left = points[0][0], right = points[0][1];
        for (int i = 1; i < points.size(); i++)
        {
            if (points[i][0] > right)
            {
                count++;
                left = points[i][0];
                right = points[i][1];
            }
            else
            {
                left = points[i][0];
                right = min(points[i][1], right);
            }
        }
        return count;
    }
};

int main()
{
    vector<vector<int>> points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    Solution sl;
    cout << sl.findMinArrowShots(points);
}
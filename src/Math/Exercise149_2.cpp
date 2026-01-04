/* Note: a better method, in a loop, if the slope is same, one point is the same, then they lie on the same line */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        if (points.size() <= 2)
            return points.size();
        int maxP = 1;
        for (int i = 0; i < points.size(); i++)
        {
            unordered_map<double, int> m;
            for (int j = i + 1; j < points.size(); j++)
            {
                double x1 = points[i][0], x2 = points[j][0];
                double y1 = points[i][1], y2 = points[j][1];
                double slope;
                if (x2 == x1)
                    slope = INT_MAX;
                else
                {
                    slope = (y1 - y2) / (x1 - x2);
                }
                m[slope]++;
                maxP = max(maxP, m[slope]);
            }
        }
        return maxP + 1;
    }
};

int main()
{
    vector<vector<int>> points = {{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}};
    Solution sl;
    cout << sl.maxPoints(points);
}

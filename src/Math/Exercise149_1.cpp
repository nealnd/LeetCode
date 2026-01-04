#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        int max = 1;
        unordered_map<string, unordered_set<int>> m;
        for (int i = 0; i < points.size(); i++)
        {
            for (int j = i + 1; j < points.size(); j++)
            {
                double x1 = points[i][0], x2 = points[j][0];
                double y1 = points[i][1], y2 = points[j][1];
                if (x1 == x2)
                {
                    m[to_string(x1)].insert(i);
                    m[to_string(x1)].insert(j);
                    if (m[to_string(x1)].size() > max)
                    {
                        max = m[to_string(x1)].size();
                    }
                }
                else
                {
                    double a = (y1 - y2) / (x1 - x2);
                    double b = (x1 * y2 - x2 * y1) / (x1 - x2);
                    m[to_string(a) + "#" + to_string(b)].insert(i);
                    m[to_string(a) + "#" + to_string(b)].insert(j);
                    if (m[to_string(a) + "#" + to_string(b)].size() > max)
                    {
                        max = m[to_string(a) + "#" + to_string(b)].size();
                    }
                }
            }
        }
        return max;
    }
};

int main(){
   vector<vector<int>> points = { { 1, 1 }, { 3, 2 }, { 5, 3 }, { 4, 1 }, { 2, 3 }, { 1, 4 } };
   Solution sl;
   cout << sl.maxPoints(points);
}


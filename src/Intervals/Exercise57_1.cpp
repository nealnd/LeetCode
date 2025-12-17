#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {

        int n = intervals.size(), i = 0;
        vector<vector<int>> res;

        while (i < n && newInterval[0] > intervals[i][1])
        {
            res.push_back(intervals[i]);
            i++;
        }
        while (i < n && newInterval[1] >= intervals[i][0])
        {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        res.push_back(newInterval);
        while (i < n)
        {
            res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> intervals({{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}});
    vector<int> newInterval({4, 8});
    Solution sl;
    for (auto vec : sl.insert(intervals, newInterval))
    {
        for (auto v : vec)
        {
            cout << v << " ";
        }
        cout << endl;
    }
}
/* Note: an awesome solution */

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {

        vector<vector<int>> res;

        for (auto &interval : intervals)
        {
            if (interval[0] > newInterval[1])
            {
                res.push_back(newInterval);
                // elegant
                newInterval = interval;
            }
            else if (interval[1] < newInterval[0])
            {
                res.push_back(interval);
            }
            else
            {
                newInterval[0] = min(newInterval[0], interval[0]);
                newInterval[1] = max(newInterval[1], interval[1]);
            }
        }
        res.push_back(newInterval);
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
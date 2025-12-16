#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] < b[0]; });
        int n = intervals.size();
        if (n <= 1)
            return intervals;
        vector<vector<int>> res;
        vector<int> prev = intervals[0];
        for (int i = 1; i < n; i++)
        {
            if (intervals[i][0] <= prev[1])
            {
                prev[1] = max(prev[1], intervals[i][1]);
            }
            else
            {
                res.push_back(prev);
                prev = intervals[i];
            }
        }
        res.push_back(prev);
        return res;
    }
};

int main()
{
    vector<vector<int>> intervals{{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    Solution sl;
    for(auto vec:sl.merge(intervals)){
        for(auto v:vec){
            cout << v << " ";
        }
        cout << endl;
    }
}
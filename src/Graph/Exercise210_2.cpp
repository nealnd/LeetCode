#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> ans;
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        for (auto prerequisity : prerequisites)
        {
            graph[prerequisity[1]].push_back(prerequisity[0]);
            indegree[prerequisity[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }
        int count = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            count++;
            ans.push_back(node);
            for (int v : graph[node])
            {
                indegree[v]--;
                if (indegree[v] == 0)
                {
                    q.push(v);
                }
            }
        }
        if (count == numCourses)
            return ans;

        return {};
    }
};

int main()
{
    vector<vector<int>> prerequisites{{1, 4}, {2, 4}, {3, 1}, {3, 2}};
    int numCourses = 5;
    Solution sl;
    for (auto i : sl.findOrder(numCourses, prerequisites))
        cout << i << " ";
}
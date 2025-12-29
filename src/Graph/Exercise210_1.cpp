#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> ans;

        vector<vector<int>> graph(numCourses);
        vector<bool> visited(numCourses, false);
        vector<bool> s(numCourses, false);

        for (auto prerequisity : prerequisites)
        {
            graph[prerequisity[1]].push_back(prerequisity[0]);
        }
        for (int i = 0; i < graph.size(); i++)
        {
            if (!visited[i])
            {
                if (hasCycle(i, graph, visited, s, ans))
                    return {};
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

private:
    bool hasCycle(int index, vector<vector<int>> &graph, vector<bool> &visited,
                  vector<bool> &s, vector<int> &ans)
    {

        visited[index] = true;
        s[index] = true;
        for (auto v : graph[index])
        {
            if (!visited[v])
            {
                if (hasCycle(v, graph, visited, s, ans))
                {

                    return true;
                }
            }
            else
            {
                if (s[v])
                {

                    return true;
                }
            }
        }
        s[index] = false;
        ans.push_back(index);
        return false;
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
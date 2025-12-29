/* Note：detect if there is a cycle */
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> graph(numCourses);
        vector<bool> visited(numCourses, false);
        vector<bool> s(numCourses, false);
        for (auto prerequisity : prerequisites)
        {
            graph[prerequisity[1]].push_back(prerequisity[0]);
        }
        for (int i = 0; i < graph.size(); i++)
        {
            if (graph[i].size() > 0)
            {
                if (hasCycle(graph, i, visited, s))
                    return false;
            }
        }
        return true;
    }

    bool hasCycle(vector<vector<int>> &graph, int index, vector<bool> &visited, vector<bool> &s)
    {

        visited[index] = true;
        s[index] = true;
        for (auto v : graph[index])
        {
            if (!visited[v])
            {
                if (hasCycle(graph, v, visited, s))
                    return true;
            }
            else
            {
                if (s[v])
                    return true;
            }
        }
        s[index] = false; // remove from recursion stack
        return false;
    }
};

int main()
{
    vector<vector<int>> prerequisites{{1, 4}, {2, 4}, {3, 1}, {3, 2}};
    int numCourses = 5;
    Solution sl;
    cout << sl.canFinish(numCourses, prerequisites);
}
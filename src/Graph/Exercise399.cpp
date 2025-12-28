/* Note: there are other ways */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        unordered_map<string, unordered_map<string, double>> graph;
        unordered_set<string> visited;
        for (int i = 0; i < equations.size(); i++)
        {
            graph[equations[i][0]][equations[i][1]] = values[i];
            graph[equations[i][1]][equations[i][0]] = 1.0 / values[i];
        }
        vector<double> ans;
        for (auto query : queries)
        {
            ans.push_back(dfs(graph, query, visited));
        }
        return ans;
    }

    double dfs(unordered_map<string, unordered_map<string, double>> &graph, vector<string> query, unordered_set<string> visited)
    {
        if (!graph.contains(query[0]))
        {
            return -1;
        }
        if (graph[query[0]].contains(query[1]))
        {
            return graph[query[0]][query[1]];
        }
        visited.insert(query[0]);
        for (auto &pair : graph[query[0]])
        {
            if (!visited.contains(pair.first))
            {
                double result = dfs(graph, {pair.first, query[1]}, visited);
                if (result != -1)
                {
                    return result * pair.second;
                }
            }
        }
        return query[0] == query[1] ? 1.0 : -1.0;
    }
};

int main()
{
    vector<vector<string>> equations{{"x1", "x2"}, {"x2", "x3"}, {"x3", "x4"}, {"x4", "x5"}};
    vector<double> values{3.0, 4.0, 5.0, 6.0};
    vector<vector<string>> queries{{"x1", "x5"}, {"x5", "x2"}, {"x2", "x4"}, {"x2", "x2"}, {"x2", "x9"}, {"x9", "x9"}};
    Solution sl;
    for (auto ans : sl.calcEquation(equations, values, queries))
    {
        cout << ans << " ";
    }
}
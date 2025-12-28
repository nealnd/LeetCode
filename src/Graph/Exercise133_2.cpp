/* Note: a simplified dfs method */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return node;
        unordered_map<Node *, Node *> m;
        dfs(node, m);
        return m[node];
    }

private:
    void dfs(Node *node, unordered_map<Node *, Node *> &m)
    {
        Node *copy = new Node(node->val);
        m[node] = copy;
        for (auto ng : node->neighbors)
        {
            // alreay have new copy node
            if (m.contains(ng))
            {
                copy->neighbors.push_back(m[ng]);
            }
            else
            {
                dfs(ng, m);
                copy->neighbors.push_back(m[ng]);
            }
        }
    }
};

int main()
{
    Node a4(4);
    Node a3(3);
    Node a2(2);
    Node a1(1);
    a1.neighbors = {&a2, &a4};
    a2.neighbors = {&a3, &a1};
    a3.neighbors = {&a4, &a2};
    a4.neighbors = {&a1, &a3};
    Solution sl;
    Node *ans = sl.cloneGraph(&a1);
}
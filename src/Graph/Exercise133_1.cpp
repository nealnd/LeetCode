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
        helper(node, nullptr, m);
        return dummy;
    }

private:
    Node *dummy;
    void helper(Node *node, Node *prev, unordered_map<Node *, Node *> &m)
    {
        if (m.contains(node))
        {
            for (auto e : m[node]->neighbors)
            {
                if (e == prev)
                    return;
            }
            prev->neighbors.push_back(m[node]);
            m[node]->neighbors.push_back(prev);
            return;
        }

        Node *curr = new Node(node->val);
        m.insert({node, curr});

        if (prev)
        {
            prev->neighbors.push_back(curr);
            curr->neighbors.push_back(prev);
        }
        else
        {
            dummy = curr;
        }
        prev = curr;

        for (auto el : node->neighbors)
        {
            helper(el, prev, m);
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

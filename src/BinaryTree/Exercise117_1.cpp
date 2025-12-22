#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node *next;
    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int x, Node *left, Node *right, Node *next = nullptr) : val(x), left(left), right(right), next(next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root)
            return root;
        queue<Node *> nodesIn;
        nodesIn.push(root);

        while (!nodesIn.empty())
        {
            int size = nodesIn.size();
            Node *prev = nullptr;
            for (int i = 0; i < size; i++)
            {
                Node *node = nodesIn.front();
                nodesIn.pop();

                if (node)
                {
                    if (prev)
                        prev->next = node;
                    prev = node;
                    nodesIn.push(node->left);
                    nodesIn.push(node->right);
                }
            }
        }
        return root;
    }
};

int main()
{

    Node a6(7);
    Node a5(5);
    Node a4(4);
    Node a3(3, &a6, &a6);
    Node a2(2, &a4, &a5);
    Node a1(1, &a2, &a3);
    Solution sl;
    Node *root = sl.connect(&a1);
}

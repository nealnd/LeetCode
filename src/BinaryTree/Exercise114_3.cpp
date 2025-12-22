#include <iostream>
#include <vector>
#include "BinaryTree.h"
using namespace std;

class Solution
{
public:
    void flatten(TreeNode *root)
    {
        if (!root)
            return;
        vector<TreeNode *> nodes;
        preorder(root, nodes);
        for (int i = 0; i < nodes.size() - 1; i++)
        {
            nodes[i]->left = nullptr;
            nodes[i]->right = nodes[i + 1];
        }
    }
    void preorder(TreeNode *node, vector<TreeNode *> &nodes)
    {
        if (!node)
            return;
        nodes.push_back(node);
        preorder(node->left, nodes);
        preorder(node->right, nodes);
    }
};

int main()
{
    TreeNode a6(6);
    TreeNode a5(4);
    TreeNode a4(3);
    TreeNode a3(5, nullptr, &a6);
    TreeNode a2(2, &a4, &a5);
    TreeNode a1(1, &a2, &a3);
    Solution sl;
    sl.flatten(&a1);
    a1.printTree(&a1);
}
#include <iostream>
#include <vector>
#include "BinaryTree.h"
using namespace std;

class Solution
{
    TreeNode *prev = nullptr;

public:
    void flatten(TreeNode *root)
    {
        if (!root)
            return;
        // Process right subtree first
        flatten(root->right);

        // Process left subtree
        flatten(root->left);

        // Set the current node's right to prev and left to null
        root->right = prev;
        root->left = nullptr;

        // Update prev to current node
        prev = root;
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
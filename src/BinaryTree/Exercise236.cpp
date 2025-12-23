/* Note:not solved by myself */

#include <iostream>
#include "BinaryTree.h"
using namespace std;

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root)
            return root;
        if (root == p || root == q)
            return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (left == nullptr && right == nullptr)
            return nullptr;
        else if (left == nullptr && right)
            return right;
        else if (left && right == nullptr)
            return left;
        else
            return root;
    }
};

int main()
{
    TreeNode a9(4);
    TreeNode a8(7);
    TreeNode a7(8);
    TreeNode a6(0);
    TreeNode a5(2, &a8, &a9);
    TreeNode a4(6, nullptr, nullptr);
    TreeNode a3(1, &a6, &a7);
    TreeNode a2(5, &a4, &a5);
    TreeNode a1(3, &a2, &a3);
    Solution sl;
    TreeNode *ans = sl.lowestCommonAncestor(&a1, &a2, &a3);
}
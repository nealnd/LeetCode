#include <iostream>
#include "BinaryTree.h"
using namespace std;

class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        return isValid(root, LONG_MIN, LONG_MAX);
    }

    bool isValid(TreeNode *node, long min, long max)
    {
        if (!node)
            return true;
        if (node->val <= min || node->val >= max)
            return false;
        return isValid(node->left, min, node->val) && isValid(node->right, node->val, max);
    }
};

int main()
{
    TreeNode a5(7);
    TreeNode a4(3);
    TreeNode a3(6, &a4, &a5);
    TreeNode a2(4);
    TreeNode a1(5, &a2, &a3);
    Solution sl;
    cout << sl.isValidBST(&a1);
}
#include <iostream>
#include "BinaryTree.h"
using namespace std;

class Solution
{
public:
    bool isCousins(TreeNode *root, int x, int y)
    {
        isCousinsHelper(root, x, y, 0);
        if (xDepth == yDepth && xDepth != 0 && isCousin)
            return true;
        else
            return false;
    }

private:
    int xDepth = 0;
    int yDepth = 0;
    bool isCousin = true;

    void isCousinsHelper(TreeNode *root, int x, int y, int level)
    {
        if (!root)
            return;
        if ((root->left && root->right) &&
            ((root->left->val == x && root->right->val == y) || (root->left->val == y && root->right->val == x)))
        {
            isCousin = false;
        }
        if (root->val == x)
            xDepth = level;
        if (root->val == y)
            yDepth = level;
        isCousinsHelper(root->left, x, y, level + 1);
        isCousinsHelper(root->right, x, y, level + 1);
    }
};
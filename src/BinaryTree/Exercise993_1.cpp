#include <iostream>
#include "BinaryTree.h"
#include <queue>
using namespace std;

class Solution
{
public:
    bool isCousins(TreeNode *root, int x, int y)
    {

        if (!root)
            return false;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            bool foundX = false, foundY = false;
            for (int i = 0; i < n; i++)
            {
                TreeNode *root = q.front();
                q.pop();
                if ((root->left && root->right) &&
                    ((root->left->val == x && root->right->val == y) || (root->left->val == y && root->right->val == x)))
                {

                    return false;
                }
                if (root->left)
                {
                    q.push(root->left);
                    if (root->left->val == x)
                        foundX = true;
                    if (root->left->val == y)
                        foundY = true;
                }
                if (root->right)
                {
                    q.push(root->right);
                    if (root->right->val == x)
                        foundX = true;
                    if (root->right->val == y)
                        foundY = true;
                }
            }
            if (foundX && foundY)
                return true;
            if (foundX || foundY)
                return false;
        }
        return false;
    }
};
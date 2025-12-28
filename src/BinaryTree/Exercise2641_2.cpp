#include <iostream>
#include "BinaryTree.h"
#include <queue>
using namespace std;

class Solution
{
public:
    TreeNode *replaceValueInTree(TreeNode *root)
    {
        if (!root)
            return root;
        queue<TreeNode *> q;
        q.push(root);
        int currentLevelSum = root->val;

        while (!q.empty())
        {
            int n = q.size();
            int nextLevelSum = 0;
            for (int i = 0; i < n; i++)
            {
                TreeNode *root = q.front();
                q.pop();
                root->val = currentLevelSum - root->val;

                int NextSum = (root->left ? root->left->val : 0) +
                              (root->right ? root->right->val : 0);
                if (root->left)
                {
                    nextLevelSum += root->left->val;
                    root->left->val = NextSum; // Update left child's value.
                    q.push(root->left);
                }

                if (root->right)
                {
                    nextLevelSum += root->right->val;
                    root->right->val = NextSum; // Update left child's value.
                    q.push(root->right);
                }
            }
            currentLevelSum = nextLevelSum;
        }

        return root;
    }
};

int main()
{
    TreeNode a6(7);
    TreeNode a5(10);
    TreeNode a4(1);
    TreeNode a3(9, nullptr, &a6);
    TreeNode a2(4, &a4, &a5);
    TreeNode a1(5, &a2, &a3);
    Solution sl;
    sl.replaceValueInTree(&a1);
    a1.printTree(&a1);
}
#include <iostream>
#include "BinaryTree.h"
#include <vector>
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
        vector<int> LevelSum;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            int sum = 0;
            for (int i = 0; i < n; i++)
            {
                TreeNode *root = q.front();
                sum += root->val;
                q.pop();
                if (root->left)
                    q.push(root->left);
                if (root->right)
                    q.push(root->right);
            }
            LevelSum.push_back(sum);
        }
        root->val = 0;
        int level = 0;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode *Node = q.front();
                q.pop();
                int leftVal = Node->left ? Node->left->val : 0;
                int rightVal = Node->right ? Node->right->val : 0;

                if (Node->left)
                {
                    Node->left->val = LevelSum[level + 1] - leftVal - rightVal;
                    q.push(Node->left);
                }

                if (Node->right)
                {
                    Node->right->val = LevelSum[level + 1] - leftVal - rightVal;
                    q.push(Node->right);
                }
            }
            level++;
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
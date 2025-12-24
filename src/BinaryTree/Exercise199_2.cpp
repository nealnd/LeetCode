#include <iostream>
#include <queue>
#include <vector>
#include "BinaryTree.h"
using namespace std;

class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        if (!root)
            return vector<int>{};
        vector<int> ans;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode *root = q.front();
                q.pop();
                // if it is the last node at this level
                if (i == n - 1)
                    ans.push_back(root->val);
                if (root->left)
                    q.push(root->left);
                if (root->right)
                    q.push(root->right);
            }
        }
        return ans;
    }
};

int main()
{
    TreeNode node8(8);
    TreeNode node7(7, nullptr, &node8);
    TreeNode node6(6);
    TreeNode node5(5, nullptr, &node7);
    TreeNode node4(4, &node5, &node6);
    TreeNode node3(3);
    TreeNode node2(2, &node3, &node4);
    TreeNode node1(1, nullptr, &node2);
    Solution sl;
    for (auto v : sl.rightSideView(&node1))
    {
        cout << v << " ";
    }
}
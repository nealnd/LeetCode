#include <iostream>
#include "BinaryTree.h"
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
            return ans;
        stack<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *root = q.top();
            q.pop();
            ans.push_back(root->val);
            if (root->right)
                q.push(root->right);
            if (root->left)
                q.push(root->left);
        }

        return ans;
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
    for (auto v : sl.preorderTraversal(&a1))
        cout << v << " ";
}
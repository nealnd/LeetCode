#include <iostream>
#include <vector>
#include <queue>
#include "BinaryTree.h"
using namespace std;

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            vector<int> temp;
            for (int i = 0; i < n; i++)
            {
                TreeNode *root = q.front();
                q.pop();
                temp.push_back(root->val);
                if (root->left)
                    q.push(root->left);
                if (root->right)
                    q.push(root->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

int main()
{
    TreeNode a7(3);
    TreeNode a6(4);
    TreeNode a5(4);
    TreeNode a4(3);
    TreeNode a3(2, &a6, &a7);
    TreeNode a2(2, &a4, &a5);
    TreeNode a1(1, &a2, &a3);
    Solution sl;
    for (auto v : sl.levelOrder(&a1))
    {
        for (auto n : v)
            cout << n << " ";
        cout << endl;
    }
}

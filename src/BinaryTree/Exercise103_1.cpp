#include <iostream>
#include <vector>
#include <queue>
#include "BinaryTree.h"
using namespace std;

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        queue<TreeNode *> q;
        q.push(root);
        bool isLeftToRight = true;
        while (!q.empty())
        {
            int n = q.size();
            vector<int> temp;
            for (int i = 0; i < n; i++)
            {
                TreeNode *root = q.front();
                q.pop();
                if (isLeftToRight)
                {
                    temp.push_back(root->val);
                }
                else
                {
                    temp.insert(temp.begin(), root->val);
                }
                if (root->left)
                    q.push(root->left);
                if (root->right)
                    q.push(root->right);
            }
            ans.push_back(temp);
            isLeftToRight = !isLeftToRight;
        }
        return ans;
    }
};
int main()
{
    TreeNode a7(7);
    TreeNode a6(15);
    TreeNode a3(20, &a6, &a7);
    TreeNode a2(9);
    TreeNode a1(3, &a2, &a3);
    Solution sl;
    for (auto v : sl.zigzagLevelOrder(&a1))
    {
        for (auto n : v)
            cout << n << " ";
        cout << endl;
    }
}
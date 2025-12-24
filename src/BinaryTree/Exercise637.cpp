#include <iostream>
#include "BinaryTree.h"
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<double> ans;
        if (!root)
            return ans;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            double sum = 0.0;

            for (int i = 0; i < n; i++)
            {
                TreeNode *root = q.front();
                q.pop();
                sum += root->val;

                if (root->left)
                    q.push(root->left);
                if (root->right)
                    q.push(root->right);
            }
            double ave = (double)sum / (double)n;
            ans.push_back(ave);
        }
        return ans;
    }
};

int main()
{
    TreeNode a4(9);
    TreeNode a5(20);
    TreeNode a3(15, &a4, &a5);
    TreeNode a2(3);
    TreeNode a1(7, &a2, &a3);
    Solution sl;
    for (auto v : sl.averageOfLevels(&a1))
    {
        cout << v << endl;
    }
}
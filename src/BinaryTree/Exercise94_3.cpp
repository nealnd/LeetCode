#include <iostream>
#include "BinaryTree.h"
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        while (root)
        {
            if (root->left)
            {
                TreeNode *pre = root->left;
                while (pre->right && pre->right != root)
                {
                    pre = pre->right;
                }
                if (!pre->right)
                {
                    pre->right = root;
                    root = root->left;
                }
                else
                {
                    pre->right = nullptr;
                    ans.push_back(root->val);
                    root = root->right;
                }
            }
            else
            {
                ans.push_back(root->val);
                root = root->right;
            }
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
    for (auto v : sl.inorderTraversal(&a1))
        cout << v << " ";
}
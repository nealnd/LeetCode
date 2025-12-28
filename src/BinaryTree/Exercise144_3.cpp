#include <iostream>
#include "BinaryTree.h"
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        TreeNode *curr = root;
        while (curr)
        {
            if (!curr->left)
            {
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else
            {
                TreeNode *predecessor = curr->left;
                while (predecessor->right && predecessor->right != curr)
                {
                    predecessor = predecessor->right;
                }
                if (predecessor->right == nullptr)
                {
                    ans.push_back(curr->val);
                    predecessor->right = curr;
                    curr = curr->left;
                }
                else
                {
                    predecessor->right = nullptr;
                    curr = curr->right;
                }
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
    for (auto v : sl.preorderTraversal(&a1))
        cout << v << " ";
}
#include <iostream>
#include "BinaryTree.h"
using namespace std;

class Solution
{
    TreeNode *prev = nullptr;

public:
    void flatten(TreeNode *root)
    {
        TreeNode *curr = root;

        while (curr)
        {
            if (curr->left)
            {
                TreeNode *temp = curr->left;
                while (temp->right)
                    temp = temp->right;
                temp->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
            }
            curr = curr->right;
        }
    }
};

int main()
{
    TreeNode a6(6);
    TreeNode a5(4);
    TreeNode a4(3);
    TreeNode a3(5, nullptr, &a6);
    TreeNode a2(2, &a4, &a5);
    TreeNode a1(1, &a2, &a3);
    Solution sl;
    sl.flatten(&a1);
}
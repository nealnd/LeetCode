#include <iostream>
#include "BinaryTree.h"
using namespace std;

class Solution
{
public:
    void flatten(TreeNode *root)
    {
        if (root == nullptr)
            return;
        ptr = root;
        flattenHelper(root);
    }

private:
    TreeNode *ptr;

    TreeNode *flattenHelper(TreeNode *root)
    {
        if (root->left == nullptr && root->right == nullptr)
            return root;
        TreeNode *tempRight = nullptr;
        if (root->left)
        {
            tempRight = root->right;
            root->right = root->left;
        }
        root->left = nullptr;
        root = root->right;
        if (root)
            ptr = flattenHelper(root);
        if (tempRight)
        {

            ptr->right = tempRight;
            ptr = ptr->right;
        }
        // ptr might have subtree
        ptr = flattenHelper(ptr);
        return ptr;
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
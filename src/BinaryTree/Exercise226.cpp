#include <iostream>
#include "BinaryTree.h"
using namespace std;

class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        invertNode(root);
        return root;
    }

private:
    void invertNode(TreeNode *root)
    {
        if(!root)
            return;
        TreeNode *temp;
        temp = root->right;
        root->right = root->left;
        root->left = temp;
        invertNode(root->left);
        invertNode(root->right);
    }
};

int main()
{
    
    TreeNode a3(20);
    TreeNode a2(9);
    TreeNode a1(2, &a2, &a3);
    a1.printTree(&a1);
    Solution sl;
    TreeNode *root = sl.invertTree(&a1);
    root->printTree(root);
}
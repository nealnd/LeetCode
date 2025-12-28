#include <iostream>
#include "BinaryTree.h"
using namespace std;

class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        isValidBSTHelper(root);
        return ans;
    }

private:
    bool ans = true;
    TreeNode *prev = nullptr;
    void isValidBSTHelper(TreeNode *root)
    {
        if (!root)
            return;
        isValidBSTHelper(root->left);
        if (prev && prev->val >= root->val)
            ans = false;
        prev = root;
        isValidBSTHelper(root->right);
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
    cout << sl.isValidBST(&a1);
}
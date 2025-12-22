#include <iostream>
#include "BinaryTree.h"
using namespace std;

class Solution
{
public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (!root)
        {
            return false;
        }

        if (!root->left && !root->right)
        {
            return targetSum == root->val;
        }

        bool left_sum = hasPathSum(root->left, targetSum - root->val);
        bool right_sum = hasPathSum(root->right, targetSum - root->val);

        return left_sum || right_sum;
    }
};

int main()
{

    TreeNode a10(1);
    TreeNode a9(2);
    TreeNode a8(7);

    TreeNode a7(4, nullptr, &a10);
    TreeNode a6(13);

    TreeNode a4(11, &a8, &a9);
    TreeNode a3(8, &a6, &a7);
    TreeNode a2(4, &a4, nullptr);
    TreeNode a1(5, &a2, &a3);
    Solution sl;
    cout << sl.hasPathSum(&a1, 22);
}

/* Note: not solved by myself, this problem should consider whether current node is taken as the root when finding the best path */
#include <iostream>
#include "BinaryTree.h"
using namespace std;

class Solution
{
public:
    int maxPathSum(TreeNode *root)
    {
        helper(root);
        return maxSum;
    }

private:
    int maxSum = INT_MIN;
    int helper(TreeNode *node)
    {
        if (!node)
            return 0;

        int leftMaxPath = max(helper(node->left), 0);
        int rightMaxPath = max(helper(node->right), 0);

        // if node is the rootNode;
        int maxIfNodeIsRoot = node->val + leftMaxPath + rightMaxPath;
        maxSum = max(maxSum, maxIfNodeIsRoot);

        return node->val + max(leftMaxPath, rightMaxPath);
    }
};
int main()
{

    TreeNode a5(7);
    TreeNode a4(15);
    TreeNode a3(20, &a4, &a5);
    TreeNode a2(9, nullptr, nullptr);
    TreeNode a1(-10, &a2, &a3);
    Solution sl;
    cout << sl.maxPathSum(&a1);
}
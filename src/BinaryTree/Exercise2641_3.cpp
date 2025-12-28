#include <iostream>
#include "BinaryTree.h"
#include <vector>
using namespace std;

class Solution
{
public:
    TreeNode *replaceValueInTree(TreeNode *root)
    {
        calculateLevelSum(root, 0);
        replaceValue(root, 0, 0);
        return root;
    }

private:
    vector<int> LevelSum;
    void calculateLevelSum(TreeNode *node, int level)
    {
        if (!node)
            return;
        if (LevelSum.size() == level)
            LevelSum.push_back({});
        LevelSum[level] += node->val;
        calculateLevelSum(node->left, level + 1);
        calculateLevelSum(node->right, level + 1);
    }

    void replaceValue(TreeNode *root, int Sum, int level)
    {
        if (!root)
            return;
        if (level == 0 || level == 1)
        {
            root->val = 0;
        }
        else
        {
            root->val = LevelSum[level] - Sum;
        }
        Sum = (root->left ? root->left->val : 0) +
              (root->right ? root->right->val : 0);

        replaceValue(root->left, Sum, level + 1);
        replaceValue(root->right, Sum, level + 1);
    }
};

int main()
{
    TreeNode a6(7);
    TreeNode a5(10);
    TreeNode a4(1);
    TreeNode a3(9, nullptr, &a6);
    TreeNode a2(4, &a4, &a5);
    TreeNode a1(5, &a2, &a3);
    Solution sl;
    sl.replaceValueInTree(&a1);
    a1.printTree(&a1);
}
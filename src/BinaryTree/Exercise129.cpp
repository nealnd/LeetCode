#include <iostream>
#include "BinaryTree.h"
using namespace std;

class Solution
{
public:
    int sumNumbers(TreeNode *root)
    {
        return sumNumbers(root, 0);
    }

private:
    int sumNumbers(TreeNode *root, int sum)
    {
        if (root == nullptr)
            return 0;
        if (root->left == nullptr && root->right == nullptr)
        {

            return sum * 10 + root->val;
        }
        sum = sum * 10 + root->val;
        int leftSum = sumNumbers(root->left, sum);
        int rightSum = sumNumbers(root->right, sum);
        return leftSum + rightSum;
    }
};

int main()
{

    TreeNode a3(2, nullptr, nullptr);
    TreeNode a2(2, nullptr, nullptr);
    TreeNode a1(1, &a2, &a3);
    Solution sl;
    cout << sl.sumNumbers(&a1);
}
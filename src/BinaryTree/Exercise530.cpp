/* Note:better way, avoids storing the full list of node values */

#include <iostream>
#include "BinaryTree.h"
using namespace std;

class Solution
{
public:
    int getMinimumDifference(TreeNode *root)
    {
        getMinimumDifferenceHelper(root);
        return minDif;
    }

private:
    int minDif = INT_MAX;
    TreeNode *prev = nullptr;

    void getMinimumDifferenceHelper(TreeNode *root)
    {
        if (!root)
            return;
        getMinimumDifferenceHelper(root->left);
        if (prev)
            minDif = min(minDif, abs(prev->val - root->val));
        prev = root;
        getMinimumDifferenceHelper(root->right);
    }
};

int main()
{
    TreeNode a4(9);
    TreeNode a5(20);
    TreeNode a3(15, &a4, &a5);
    TreeNode a2(3);
    TreeNode a1(7, &a2, &a3);
    Solution sl;
    cout << sl.getMinimumDifference(&a1);
}
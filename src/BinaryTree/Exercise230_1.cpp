#include <iostream>
#include "BinaryTree.h"
using namespace std;

class Solution
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        kthSmallestHelper(root, k);
        return ans;
    }

private:
    int index = 0;
    int ans;
    void kthSmallestHelper(TreeNode *root, int k)
    {
        if (!root)
            return;
        kthSmallest(root->left, k);
        index++;
        if (index == k)
        {
            ans = root->val;
            return;
        }
        kthSmallest(root->right, k);
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
    cout << sl.kthSmallest(&a1, 2);
}
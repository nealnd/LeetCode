#include <iostream>
#include "BinaryTree.h"
using namespace std;

class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        if (!root)
            return 0;
        num++;
        countNodes(root->left);
        countNodes(root->right);
        return num;
    }

private:
    int num = 0;
};

int main()
{
    TreeNode a3(2, nullptr, nullptr);
    TreeNode a2(2, nullptr, nullptr);
    TreeNode a1(1, &a2, &a3);
    Solution sl;
    cout << sl.countNodes(&a1);
}
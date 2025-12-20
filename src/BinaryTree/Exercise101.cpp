#include <iostream>
#include "BinaryTree.h"
using namespace std;

class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        return isSame(root->left, root->right);
    }

private:
    bool isSame(TreeNode *p, TreeNode *q)
    {
        if (!p || !q)
            return p == q;
        return p->val == q->val &&
               isSame(p->left, q->right) & isSame(p->right, q->left);
    }
};

int main()
{
    TreeNode a7(3);
    TreeNode a6(4);
    TreeNode a5(4);
    TreeNode a4(3);
    TreeNode a3(2, &a6, &a7);
    TreeNode a2(2,&a4,&a5);
    TreeNode a1(1, &a2, &a3);
    Solution sl;
    cout << sl.isSymmetric(&a1);
}

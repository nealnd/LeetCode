#include <iostream>
#include "BinaryTree.h"
using namespace std;

class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)
            return true;
        else if (p && q)
            return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        else
            return false;
    }
};

int main(){
    TreeNode a5(7);
    TreeNode a4(15);
    TreeNode a3(20, &a4, &a5);
    TreeNode a2(9);
    TreeNode a1(3, &a2, &a3);

    TreeNode b5(7);
    TreeNode b4(15);
    TreeNode b3(20, &b4, &b5);
    TreeNode b2(9);
    TreeNode b1(3, &b2, &b3);
    Solution sl;
    cout << sl.isSameTree(&a1,&b1);
}
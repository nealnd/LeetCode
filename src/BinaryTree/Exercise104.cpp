#include<iostream>
#include"BinaryTree.h"
using namespace std;

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if(root==nullptr)
            return 0;
        return max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
    }
};

int main(){
    TreeNode a5(7);
    TreeNode a4(15);
    TreeNode a3(20, &a4, &a5);
    TreeNode a2(9);
    TreeNode a1(3, &a2, &a3);
    Solution sl;
    cout << sl.maxDepth(&a1);
}
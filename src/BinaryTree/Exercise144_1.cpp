#include <iostream>
#include "BinaryTree.h"
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        preorderTraversal(root, ans);
        return ans;
    }

private:
    void preorderTraversal(TreeNode *root, vector<int> &ans)
    {
        if (!root)
            return;
        ans.push_back(root->val);
        preorderTraversal(root->left, ans);
        preorderTraversal(root->right, ans);
    }
};

int main()
{
    TreeNode a5(7);
    TreeNode a4(3);
    TreeNode a3(6, &a4, &a5);
    TreeNode a2(4);
    TreeNode a1(5, &a2, &a3);
    Solution sl;
    for (auto v : sl.preorderTraversal(&a1))
        cout << v << " ";
}
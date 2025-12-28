#include <iostream>
#include "BinaryTree.h"
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> result;
        if (root)
        {
            vector<int> left = postorderTraversal(root->left);
            vector<int> right = postorderTraversal(root->right);
            result.insert(result.end(), left.begin(), left.end());
            result.insert(result.end(), right.begin(), right.end());
            result.push_back(root->val);
        }
        return result;
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
    for (auto v : sl.postorderTraversal(&a1))
        cout << v << " ";
}
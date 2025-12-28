/* Note：Iterative solution using stack */

#include <iostream>
#include "BinaryTree.h"
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> result;
        stack<TreeNode *> todo;
        TreeNode *last = nullptr;
        while (root || !todo.empty())
        {
            if (root)
            {
                todo.push(root);
                root = root->left;
            }
            else
            {
                TreeNode *node = todo.top();
                if (node->right && last != node->right)
                {
                    root = node->right;
                }
                else
                {
                    result.push_back(node->val);
                    last = node;
                    todo.pop();
                }
            }
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
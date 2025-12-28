/* Note: Morris traversal */
#include <iostream>
#include "BinaryTree.h"
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> v;
        TreeNode *dummy = new TreeNode(0);
        dummy->left = root;
        TreeNode *cur = dummy;
        while (cur)
        {
            if (cur->left)
            {
                TreeNode *pre = cur->left;
                while (pre->right && pre->right != cur)
                    pre = pre->right;
                if (!(pre->right))
                {
                    pre->right = cur;
                    cur = cur->left;
                }
                else
                {
                    pre->right = NULL;
                    reverseAddNodes(cur->left, pre, v);
                    cur = cur->right;
                }
            }
            else
            {
                cur = cur->right;
            }
        }
        return v;
    }

private:
    void reverseNodes(TreeNode *start)
    {
        TreeNode *x = start;
        TreeNode *y = NULL;
        TreeNode *z = NULL;
        while (x != NULL)
        {
            y = x->right;
            x->right = z;
            z = x;
            x = y;
        }
    }
    void reverseAddNodes(TreeNode *start, TreeNode *end, vector<int> &nodes)
    {
        reverseNodes(start);
        TreeNode *node = end;
        while (true)
        {
            nodes.push_back(node->val);
            if (node == start)
            {
                break;
            }
            node = node->right;
        }
        reverseNodes(end);
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
/* Note: A better way,
If the current node has no left child, we visit the node, increment the count, and check if it is the k-th visited node. Then we move to the right child.

If the current node has a left child, we find its inorder predecessor (the rightmost node in the left subtree).

If the predecessor’s right pointer is null, we create a temporary link from the predecessor to the current node and move to the left child.

If the predecessor’s right pointer already points to the current node, we remove the temporary link, visit the current node, increment the count, check if it is the k-th node, and move to the right child. */

#include <iostream>
#include "BinaryTree.h"
using namespace std;

class Solution
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        int count = 0;
        int ans;
        TreeNode *curr = root;
        while (curr)
        {
            if (curr->left == nullptr)
            {
                count++;
                if (count == k)
                    ans = curr->val;
                curr = curr->right;
            }
            else
            {
                TreeNode *temp = curr->left;
                while (temp->right != nullptr && temp->right != curr)
                {
                    temp = temp->right;
                }
                if (temp->right == nullptr)
                {
                    temp->right = curr;
                    curr = curr->left;
                }
                else if (temp->right == curr)
                {
                    temp->right = NULL;
                    count++;
                    if (count == k)
                        ans = curr->val;
                    curr = curr->right;
                }
            }
        }
        return ans;
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
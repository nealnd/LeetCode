#include <iostream>
#include <vector>
#include "BinaryTree.h"
using namespace std;

class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        rightSideView(root, 0, ans);
        return ans;
    }

private:
    void rightSideView(TreeNode *root, int n, vector<int> &vec)
    {
        if (!root)
            return;
        if (vec.size() <= n)
        {
            vec.push_back(root->val);
        }

        // vec.push_back(root->val);
        rightSideView(root->right, n + 1, vec);
        rightSideView(root->left, n + 1, vec);
    }
};

int main()
{
    TreeNode node8(8);
    TreeNode node7(7, nullptr, &node8);
    TreeNode node6(6);
    TreeNode node5(5, nullptr, &node7);
    TreeNode node4(4, &node5, &node6);
    TreeNode node3(3);
    TreeNode node2(2, &node3, &node4);
    TreeNode node1(1, nullptr, &node2);
    Solution sl;
    for (auto v : sl.rightSideView(&node1))
    {
        cout << v << " ";
    }
}
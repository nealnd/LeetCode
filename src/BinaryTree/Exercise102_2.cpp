#include <iostream>
#include <vector>
#include "BinaryTree.h"
using namespace std;

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {

        levelOrderHelper(root, 0);
        return ans;
    }

private:
    vector<vector<int>> ans;
    void levelOrderHelper(TreeNode *root, int level)
    {
        if (!root)
            return;
        if (ans.size() == level)
            ans.push_back({});
        ans[level].push_back(root->val);
        levelOrderHelper(root->left, level + 1);
        levelOrderHelper(root->right, level + 1);
    }
};

int main()
{
    TreeNode a7(3);
    TreeNode a6(4);
    TreeNode a5(4);
    TreeNode a4(3);
    TreeNode a3(2, &a6, &a7);
    TreeNode a2(2, &a4, &a5);
    TreeNode a1(1, &a2, &a3);
    Solution sl;
    for (auto v : sl.levelOrder(&a1))
    {
        for (auto n : v)
            cout << n << " ";
        cout << endl;
    }
}

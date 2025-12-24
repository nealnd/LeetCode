#include <iostream>
#include <vector>
#include "BinaryTree.h"
using namespace std;

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {

        zigzagLevelOrder(root, 0, true);
        return ans;
    }

private:
    vector<vector<int>> ans;
    void zigzagLevelOrder(TreeNode *root, int level, bool isLeftToRight)
    {
        if (!root)
            return;
        if (ans.size() == level)
            ans.push_back({});
        if (isLeftToRight)
        {
            ans[level].push_back(root->val);
        }
        else
        {
            ans[level].insert(ans[level].begin(), root->val);
        }
        zigzagLevelOrder(root->left, level + 1, !isLeftToRight);
        zigzagLevelOrder(root->right, level + 1, !isLeftToRight);
    }
};
int main()
{
    TreeNode a7(7);
    TreeNode a6(15);
    TreeNode a3(20, &a6, &a7);
    TreeNode a2(9);
    TreeNode a1(3, &a2, &a3);
    Solution sl;
    for (auto v : sl.zigzagLevelOrder(&a1))
    {
        for (auto n : v)
            cout << n << " ";
        cout << endl;
    }
}
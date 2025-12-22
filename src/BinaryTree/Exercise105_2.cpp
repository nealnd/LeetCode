/* Note:not solved by myself, pay attention to the index */
#include <iostream>
#include "BinaryTree.h"
#include <unordered_map>
using namespace std;

class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < preorder.size(); i++)
        {
            inorderMap.insert({inorder[i], i});
        }
        return buildTree(preorder, 0, (int)preorder.size() - 1, inorderMap);
    }

private:
    int index = 0;

    TreeNode *buildTree(vector<int> &preorder, int start, int end, unordered_map<int, int> &inorderMap)
    {

        if (start > end)
            return nullptr;

        int rootVal = preorder[index++];
        TreeNode *root = new TreeNode(rootVal);
        int mid = inorderMap[rootVal];
        root->left = buildTree(preorder, start, mid - 1, inorderMap);
        root->right = buildTree(preorder, mid + 1, end, inorderMap);
        return root;
    }
};

int main()
{
    vector<int> preorder{1, 2, 4, 8, 9, 5, 10, 11, 3, 6, 12, 13, 7, 14, 15};
    vector<int> inorder{8, 4, 9, 2, 10, 5, 11, 1, 12, 6, 13, 3, 14, 7, 15};
    Solution sl;
    TreeNode *root = sl.buildTree(preorder, inorder);
    root->printTree(root);
}
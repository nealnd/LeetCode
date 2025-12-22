#include <iostream>
#include <unordered_map>
#include "BinaryTree.h"
using namespace std;

class Solution
{
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); i++)
        {
            inorderMap.insert({inorder[i], i});
        }
        return buildTree(postorder, 0, (int)postorder.size() - 1, inorderMap);
    }

private:
    int index = 0;

    TreeNode *buildTree(vector<int> &postorder, int start, int end, unordered_map<int, int> &inorderMap)
    {
        if (start > end)
            return nullptr;
        int rootVal = postorder[postorder.size() - 1 - index];
        index++;
        TreeNode *root = new TreeNode(rootVal);
        int mid = inorderMap[rootVal];
        root->right = buildTree(postorder, mid + 1, end, inorderMap);
        root->left = buildTree(postorder, start, mid - 1, inorderMap);
        return root;
    }
};

int main()
{
    vector<int> postorder{9, 15, 7, 20, 3};
    vector<int> inorder{9, 3, 15, 20, 7};
    Solution sl;
    TreeNode *root = sl.buildTree(inorder, postorder);
    root->printTree(root);
}
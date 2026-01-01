#include <iostream>
#include <vector>
#include "BinaryTree.h"
using namespace std;

class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }

private:
    TreeNode *sortedArrayToBST(vector<int> &nums, int left, int right)
    {
        if (left > right)
            return nullptr;

        int mid = left + (right - left) / 2;

        TreeNode *root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBST(nums, left, mid - 1);
        root->right = sortedArrayToBST(nums, mid + 1, right);
        return root;
    }
};

int main()
{
    vector<int> nums{-10, -3, 0, 5, 9};
    Solution sl;
    sl.sortedArrayToBST(nums);
}
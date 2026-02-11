/* Note:  */
#include <iostream>
#include "BinaryTree.h"
#include <queue>
using namespace std;

class Solution
{
public:
    long long kthLargestLevelSum(TreeNode *root, int k)
    {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int n = q.size();
            long long sum = 0;
            for (int i = 0; i < n; i++)
            {
                TreeNode *root = q.front();
                sum += root->val;
                q.pop();
                if (root->left)
                    q.push(root->left);
                if (root->right)
                    q.push(root->right);
            }
            if (pq.size() < k)
                pq.push(sum);
            else
            {
                if (sum > pq.top())
                {
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
        if (pq.size() < k)
            return -1;
        return pq.top();
    }
};
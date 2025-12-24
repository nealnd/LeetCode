/* Note:not solved by myself as I think next() can not meet the average(1) requirement.
 average O(1) means run n times*/

#include <iostream>
#include <stack>
#include "BinaryTree.h"
using namespace std;

class BSTIterator
{
public:
    BSTIterator(TreeNode *root)
    {
        pushLeft(root);
    }

    int next()
    {

        TreeNode *ans = s.top();
        s.pop();
        pushLeft(ans->right);
        return ans->val;
    }

    bool hasNext()
    {
        return !s.empty();
    }

private:
    stack<TreeNode *> s;
    void pushLeft(TreeNode *root)
    {
        while (root)
        {
            s.push(root);
            root = root->left;
        }
    }
};

int main()
{
    TreeNode a4(9);
    TreeNode a5(20);
    TreeNode a3(15, &a4, &a5);
    TreeNode a2(3);
    TreeNode a1(7, &a2, &a3);

    BSTIterator bSTIterator(&a1);
    cout << bSTIterator.next() << endl;
    cout << bSTIterator.next() << endl;
    cout << bSTIterator.hasNext() << endl;
    cout << bSTIterator.next() << endl;
    cout << bSTIterator.hasNext() << endl;
    cout << bSTIterator.next() << endl;
    cout << bSTIterator.hasNext() << endl;
    cout << bSTIterator.next() << endl;
    cout << bSTIterator.hasNext() << endl;
}
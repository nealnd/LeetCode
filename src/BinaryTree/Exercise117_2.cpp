#include <iostream>

using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node *next;
    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int x, Node *left, Node *right, Node *next = nullptr) : val(x), left(left), right(right), next(next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (root == nullptr)
            return root;
        Node *levelStart = root;

        while (levelStart != nullptr)
        {
            Node *curr = levelStart;
            Node *dummy = new Node();
            Node *prev = dummy;
            while (curr)
            {
                if (curr->left)
                {
                    prev->next = curr->left;
                    prev = prev->next;
                }
                if (curr->right)
                {
                    prev->next = curr->right;
                    prev = prev->next;
                }
                curr = curr->next;
            }
            levelStart = dummy->next; // move to the next level
            delete dummy;
        }
        return root;
    }
};

int main()
{

    Node a6(7);
    Node a5(5);
    Node a4(4);
    Node a3(3, &a6, &a6);
    Node a2(2, &a4, &a5);
    Node a1(1, &a2, &a3);
    Solution sl;
    Node *root = sl.connect(&a1);
}

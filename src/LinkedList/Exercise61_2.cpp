#include <iostream>
#include "LinkedList.h"
using namespace std;

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head)
            return head;

        int length = 1;
        ListNode *dummy = head;

        while (dummy->next)
        {
            dummy = dummy->next;
            length++;
        }

        int position = k % length;
        if (position == 0)
            return head;

        ListNode *current = head;
        for (int i = 0; i < length - position - 1; ++i)
        {
            current = current->next;
        }

        ListNode *newHead = current->next;
        current->next = nullptr;
        dummy->next = head;

        return newHead;
    }
};

int main()
{

    ListNode a5(5);
    ListNode a4(4, &a5);
    ListNode a3(3, &a4);
    ListNode a2(2, &a3);
    ListNode a1(1, &a2);

    Solution sl;
    ListNode *head = sl.rotateRight(&a1, 2);
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
}
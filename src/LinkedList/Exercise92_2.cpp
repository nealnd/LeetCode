#include <iostream>
#include "LinkedList.h"

using namespace std;

class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (!head || left == right)
            return head;

        ListNode dummy;
        dummy.next = head;
        ListNode *prev = &dummy;
        for (int i = 0; i < left - 1; ++i)
        {
            prev = prev->next;
        }

        ListNode *cur = prev->next;

        for (int i = 0; i < right - left; ++i)
        {
            ListNode *nextNode = cur->next;
            cur->next = nextNode->next;
            nextNode->next = prev->next;
            prev->next = nextNode;
        }
        return dummy.next;
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
    ListNode *head = sl.reverseBetween(&a1, 2, 4);
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
}
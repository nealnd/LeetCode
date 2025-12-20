#include <iostream>
#include "LinkedList.h"
using namespace std;

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {

        ListNode dummy;
        dummy.next = head;
        ListNode *prev = &dummy;
        ListNode *cur = head;

        for (int i = 0; i < n - 1 && cur; i++)
        {
            cur = cur->next;
        }

        while (cur->next)
        {
            cur = cur->next;
            prev = prev->next;
        }

        prev->next = prev->next->next;
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
    ListNode *head = sl.removeNthFromEnd(&a1, 2);
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
}
#include <iostream>
#include "LinkedList.h"
using namespace std;

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head)
            return head;
        ListNode dummy(head->val - 1, head);
        ListNode *prev = &dummy;
        ListNode *cur = head;
        int count = 0;

        while (cur)
        {
            if (cur->next && cur->val == cur->next->val)
            {
                count++;
            }
            else
            {
                if (count == 0)
                {
                    prev->next = cur;
                    prev = cur;
                }

                count = 0;
            }
            cur = cur->next;
        }
        prev->next = cur;
        return dummy.next;
    }
};

int main()
{

    ListNode a7(5);
    ListNode a6(4, &a7);
    ListNode a5(4, &a6);
    ListNode a4(3, &a5);
    ListNode a3(3, &a4);
    ListNode a2(2, &a3);
    ListNode a1(1, &a2);

    Solution sl;
    ListNode *head = sl.deleteDuplicates(&a1);
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
}
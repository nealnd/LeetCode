#include <iostream>
#include "LinkedList.h"
using namespace std;

class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        if (!head || !head->next)
            return head;
        ListNode smallDummy;
        ListNode *smallPrev = &smallDummy;
        ListNode bigDummy;
        ListNode *bigPrev = &bigDummy;

        ListNode *cur = head;

        while (cur)
        {
            if (cur->val < x)
            {
                smallPrev->next = cur;
                smallPrev = cur;
            }
            else
            {
                bigPrev->next = cur;
                bigPrev = cur;
            }
            cur = cur->next;
        }
        smallPrev->next = bigDummy.next;
        bigPrev->next = nullptr;
        return smallDummy.next;
    }
};

int main()
{

    ListNode a6(2);
    ListNode a5(5, &a6);
    ListNode a4(2, &a5);
    ListNode a3(3, &a4);
    ListNode a2(4, &a3);
    ListNode a1(1, &a2);

    Solution sl;
    ListNode *head = sl.partition(&a1, 3);
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
}
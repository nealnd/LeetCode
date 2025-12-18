#include <iostream>
#include "LinkedList.h"
using namespace std;

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode dummy(0);
        ListNode *pt = &dummy;
        int carry = 0;

        while (l1 || l2 || carry)
        {
            int i = l1 ? l1->val : 0;
            int j = l2 ? l2->val : 0;

            int sum = i + j + carry;
            carry = sum / 10;

            pt->next = new ListNode(sum % 10);
            pt = pt->next;

            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }

        return dummy.next;
    }
};

int main()
{

    ListNode a3(3);
    ListNode a2(4, &a3);
    ListNode a1(2, &a2);

    ListNode b3(4);
    ListNode b2(6, &b3);
    ListNode b1(5, &b2);

    Solution sl;
    ListNode *head = sl.addTwoNumbers(&a1, &b1);
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
}
#include <iostream>
#include "LinkedList.h"
using namespace std;

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode res;
        ListNode *pt = &res;
        while (list1 || list2)
        {
            if ((list1 && list2 && (list1->val < list2->val)) || (list1 && !list2))
            {
                pt->next = list1;
                list1 = list1->next;
            }

            else
            {
                pt->next = list2;
                list2 = list2->next;
            }
            pt = pt->next;
        }
        return res.next;
    }
};

int main()
{

    ListNode a3(4);
    ListNode a2(3, &a3);
    ListNode a1(2, &a2);

    ListNode b3(5);
    ListNode b2(3, &b3);
    ListNode b1(1, &b2);

    Solution sl;
    ListNode *head = sl.mergeTwoLists(&a1, &b1);
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
}
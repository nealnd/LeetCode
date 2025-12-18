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
            if ((list1&&list2&& (list1->val < list2->val))||(list1&&!list2))
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
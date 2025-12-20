#include <iostream>
#include "LinkedList.h"

using namespace std;

class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (left == right)
            return head;
        ListNode *pt = head;
        int count = 1;
        ListNode *PreLeftPt = nullptr;
        while (pt->next != nullptr && count < left)
        {
            PreLeftPt = pt;
            pt = pt->next;
            count++;
        }
        ListNode *leftPt = pt;
        ListNode *prePt = nullptr;
        count--;
        while (pt != nullptr && count < right)
        {
            ListNode *nextPt = pt->next;
            pt->next = prePt;
            prePt = pt;
            pt = nextPt;
            count++;
            if (count == right)
            {
                leftPt->next = nextPt;
                if (PreLeftPt)
                    PreLeftPt->next = prePt;
            }
        }
        return left == 1 ? prePt : head;
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
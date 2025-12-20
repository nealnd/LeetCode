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
        ListNode *pt = head;
        int length = 0;
        while (pt)
        {
            pt = pt->next;
            length++;
        }
        k = k % length;
        head = reverseLinkedList(head, 1, length);
        head = reverseLinkedList(head, 1, k);
        head = reverseLinkedList(head, k + 1, length);
        return head;
    }

private:
    ListNode *reverseLinkedList(ListNode *head, int left, int right)
    {
        if (!head || left == right)
            return head;
        ListNode dummy;
        dummy.next = head;
        ListNode *prev = &dummy;

        for (int i = 0; i < left - 1; i++)
        {
            prev = prev->next;
        }
        ListNode *cur = prev->next;

        for (int i = 0; i < right - left; i++)
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
    ListNode *head = sl.rotateRight(&a1, 2);
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
}
#include <iostream>
#include "LinkedList.h"

using namespace std;

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast!=nullptr&&fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(fast==slow)
                return true;
        }
        return false;
    }
};

int main(){

    
    ListNode node4(4,nullptr);
    ListNode node3(0, &node4);
    ListNode node2(2, &node3);
    ListNode node1(3, &node2);
    node4.next = &node2;

    Solution sl;
    cout << sl.hasCycle(&node1);
}

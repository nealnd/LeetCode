struct ListNode
{
    int val;
    ListNode *next;
    ListNode() {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *Node) : val(x), next(Node) {}
};
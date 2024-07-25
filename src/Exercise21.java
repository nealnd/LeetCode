public class Exercise21 {
    public class ListNode {

        int val;
        ListNode next;

        ListNode() {
        }

        ListNode(int val) {
            this.val = val;
        }

        ListNode(int val, ListNode next) {
            this.val = val;
            this.next = next;
        }

    }

    class Solution {
        public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
            ListNode first = list1;
            ListNode second = list2;
            ListNode prev;
            if (first.val < second.val) {
                while (first.val < second.val) {
                    prev = first;
                    first = first.next;
                }
            } else {
                while (second.val <= first.val) {
                    prev = second;
                    second = second.next;

                }

            }

            return first;

        }
    }
}

package LinkedList;

public class Exercise2 {

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

        public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
            ListNode l3 = new ListNode();
            ListNode first = l3;
            int carry = 0;
            while (l1 != null || l2 != null || carry == 1) {
                int i, j;
                i = (l1 == null) ? 0 : l1.val;
                j = (l2 == null) ? 0 : l2.val;
                ListNode current = new ListNode((i + j + carry) % 10);
                l3.next = current;
                l3 = l3.next;
                carry = (i + j + carry) / 10;
                if (l1 != null) {
                    l1 = l1.next;
                }
                if (l2 != null) {
                    l2 = l2.next;
                }
            }
            return first.next;
        }
    }
    public static void main(String[] args) {
        Exercise2 exercise = new Exercise2();
        Solution solution = exercise.new Solution();
        ListNode a4 = exercise.new ListNode(9);
        ListNode a3 = exercise.new ListNode(9, a4);
        ListNode a2 = exercise.new ListNode(9, a3);
        ListNode a1 = exercise.new ListNode(9, a2);
        ListNode a0 = exercise.new ListNode(9, a1);

   
        ListNode b2 = exercise.new ListNode(9);
        ListNode b1 = exercise.new ListNode(9, b2);
        ListNode b0 = exercise.new ListNode(9, b1);

        ListNode first = solution.addTwoNumbers(a0, b0);
        for (; first != null; first = first.next) {
            System.out.println(first.val);
        }
    }
}

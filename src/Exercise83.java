public class Exercise83 {
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
        public ListNode deleteDuplicates(ListNode head) {
            ListNode pre = new ListNode();
            ListNode first = pre;
            if (head == null)
                return null;
            while (head.next != null) {
                if (head.next.val == head.val) {
                    head = head.next;
                    continue;
                }
                pre.next = head;
                head = head.next;
                pre = pre.next;
            }
            pre.next = head;
            return first.next;
        }
    }
    public static void main(String[] args) {
        Exercise83 exercise = new Exercise83();
        Solution solution = exercise.new Solution();
        ListNode a4 = exercise.new ListNode(3);
        ListNode a3 = exercise.new ListNode(2, a4);
        ListNode a2 = exercise.new ListNode(2, a3);
        ListNode a1 = exercise.new ListNode(1, a2);
        ListNode a0 = exercise.new ListNode(1, a3);
        
        ListNode first = solution.deleteDuplicates(a0);
        for (; first != null; first = first.next) {
            System.out.println(first.val);
        }
    }

}

package LinkedList;
public class Exercise2130 {
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
        public int pairSum(ListNode head) {
            ListNode fast = head;
            ListNode slow = head;
            int max = Integer.MIN_VALUE;
            while (fast.next != null && fast.next.next != null) {
                fast = fast.next.next;
                slow = slow.next;
            }
            if (fast.next == null)
                max = slow.val;

            ListNode pre = new ListNode();
            ListNode next;
            ListNode cur = slow.next;
            ListNode temp = slow.next;
            slow.next = null;
            while (cur!= null) {
                next = cur.next;
                cur.next = pre;
                pre = cur;
                cur = next;
            }

            temp.next = slow;
            while (pre != slow) {
                max = Math.max(max, pre.val + head.val);
                pre = pre.next;
                head = head.next;
            }

            return max;
        }

    }
    

    public static void main(String[] args) {
        Exercise2130 exercise = new Exercise2130();
        Solution solution = exercise.new Solution();
       // ListNode a4 = exercise.new ListNode(5);
        ListNode a3 = exercise.new ListNode(1);
        ListNode a2 = exercise.new ListNode(2, a3);
        ListNode a1 = exercise.new ListNode(4, a2);
        ListNode a0 = exercise.new ListNode(5, a1);
        


            System.out.println(solution.pairSum(a0));
        
    }
}

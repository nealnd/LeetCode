public class Exercise328 {
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
        public ListNode oddEvenList(ListNode head) {
            if (head == null || head.next == null)
                return head;
            ListNode first = head;
            ListNode second = head.next;
            ListNode temp = head.next; 
            while (second != null&&second.next!=null) {
                first.next = second.next;
                first = first.next;
                second.next = first.next;
                second = second.next;
            }
            first.next = temp;

            return head;
        }
    }



    public static void main(String[] args) {
        Exercise328 exercise = new Exercise328();
        Solution solution = exercise.new Solution();
         ListNode a4 = exercise.new ListNode(5);
        ListNode a3 = exercise.new ListNode(4,a4);
        ListNode a2 = exercise.new ListNode(3, a3);
        ListNode a1 = exercise.new ListNode(2, a2);
        ListNode a0 = exercise.new ListNode(1, a1);
        
        ListNode first = solution.oddEvenList(a0);
        for (; first != null; first = first.next) {
            System.out.println(first.val);
        }
    }
}

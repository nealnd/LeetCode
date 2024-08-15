package LinkedList;
public class Exercise2095 {

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
        public ListNode deleteMiddle(ListNode head) {
            int i = 0;
            ListNode first = head;
            ListNode pt = head;
            ListNode temp = head;
            while (head != null) {
                head = head.next;
                i++;
                if (i % 2 == 0) {
                    temp = pt;
                    pt = pt.next;
                }
            }
            if (pt == first)
            {
                first = null;
                return first;
                }
            if (pt == null)
                temp.next = null;
            else {
                temp.next = pt.next;
            }
            return first;
        }
    }
    
    public static void main(String[] args) {
        Exercise2095 exercise = new Exercise2095();
        Solution solution = exercise.new Solution();
       // ListNode a4 = exercise.new ListNode(5);
        ListNode a3 = exercise.new ListNode(4);
        ListNode a2 = exercise.new ListNode(3, a3);
        ListNode a1 = exercise.new ListNode(2, a2);
        ListNode a0 = exercise.new ListNode(1, a1);
        
        ListNode first = solution.deleteMiddle(a0);
        for (; first != null; first = first.next) {
            System.out.println(first.val);
        }
    }

}

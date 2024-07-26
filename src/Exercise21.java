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
            ListNode first = new ListNode();
            ListNode prev = first;
            if (list1 == null && list2 == null)
                return null;
            while (list1 != null && list2 != null) {

                if (list1.val < list2.val) {
                    prev.next = list1;
                    list1 = list1.next;
                } else {
                    prev.next = list2;
                    list2 = list2.next;
                }
                prev = prev.next;
            }
            if (list1 == null)
                prev.next = list2;
            else
                prev.next = list1;

            return first.next;
        }

    }

    public static void main(String[] args) {

        Exercise21 exercise = new Exercise21();
        Solution solution = exercise.new Solution();

        ListNode list1_3 = exercise.new ListNode(4);
        ListNode list1_2 = exercise.new ListNode(2, list1_3);
        ListNode list1_1 = exercise.new ListNode(1, list1_2);

        ListNode list2_3 = exercise.new ListNode(4);
        ListNode list2_2 = exercise.new ListNode(3, list2_3);
        ListNode list2_1 = exercise.new ListNode(1, list2_2);

        ListNode first = solution.mergeTwoLists(list1_1, list2_1);
        for (; first != null; first = first.next)
            System.out.println(first.val);
    }

}

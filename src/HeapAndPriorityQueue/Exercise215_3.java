package HeapAndPriorityQueue;

import java.util.PriorityQueue;

public class Exercise215_3 {
    class Solution {
        public int findKthLargest(int[] nums, int k) {
            PriorityQueue<Integer> pq = new PriorityQueue<>();
            for (int val : nums) {
                pq.offer(val);

                if (pq.size() > k)
                    pq.poll();
            }
            return pq.peek();

        }
    }
    public static void main(String[] args) {
        Exercise215_3 exercise = new Exercise215_3();
        Solution solution = exercise.new Solution();
        int[] nums = new int[] { 3, 2, 1, 5, 6, 4 };

        System.out.println(solution.findKthLargest(nums, 2));
    }
}

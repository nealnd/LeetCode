package HeapAndPriorityQueue;



public class Exercise215_1 {
    class Solution {
        public int findKthLargest(int[] nums, int k) {
            int[] pq = new int[nums.length + 1];
            for (int i = 0; i < nums.length; i++)
                pq[i + 1] = nums[i];
            for (int i = pq.length / 2; i >= 1; i--)
                sink(i, pq);
            for (int i = 1; i < k; i++)
                deleteMax(pq);
            return deleteMax(pq);

        }

        private void swap(int i, int j, int[] pq) {
            int temp = pq[i];
            pq[i] = pq[j];
            pq[j] = temp;
        }

        private void swim(int i, int[] pq) {
            while (i > 1 && pq[i / 2] < pq[i]) {
                swap(i / 2, i, pq);
                i = i / 2;
            }

        }

        private void sink(int i, int[] pq) {
            while (2 * i <= pq.length - 1) {
                int j = i * 2;
                if (j < pq.length - 1 && pq[j] < pq[j + 1])
                    j++;
                if (pq[i] >= pq[j])
                    break;
                swap(i, j, pq);
                i = j;

            }
        }

        private int deleteMax(int[] pq) {
            int max = pq[1];
            swap(1, pq.length - 1, pq);
            pq[pq.length - 1] = Integer.MIN_VALUE;
            sink(1, pq);

            return max;
        }
    }
        public static void main(String[] args) {
        Exercise215_1 exercise = new Exercise215_1();
        Solution solution = exercise.new Solution();
        int[] nums = new int[] { 3, 2, 1, 5, 6, 4 };
        
        System.out.println(solution.findKthLargest(nums, 2));
    }

}

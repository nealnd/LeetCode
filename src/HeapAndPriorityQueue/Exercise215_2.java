package HeapAndPriorityQueue;

import java.util.Random;

public class Exercise215_2 {
    class Solution {
        public int findKthLargest(int[] nums, int k) {
            shuffle(nums);
            int start = 0, end = nums.length - 1, index = nums.length - k;
            int pivot = partition(nums, start, end);
            while (pivot != index) {
                if (pivot < index)
                    start = pivot + 1;
                else if (pivot > index)
                    end = pivot - 1;
                pivot = partition(nums, start, end);
            }
            return nums[pivot];
        }

        private int partition(int[] nums, int lo, int hi) {
            int i = lo;
            int j = hi + 1;
            while (true) {
                while (i < hi && less(nums[++i], nums[lo]))
                    ;
                while (j > lo && less(nums[lo], nums[--j]))
                    ;
                if (i >= j) {
                    break;
                }
                swap(i, j, nums);
            }
            swap(lo, j, nums);
            return j;
        }

        private void swap(int i, int j, int[] nums) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }

        private void shuffle(int[] nums) {
            Random random = new Random();
            for (int i = 0; i < nums.length; i++) {
                int r = i + random.nextInt(nums.length - i);
                swap(i, r, nums);
            }
        }

        private boolean less(int v, int w) {
            return v < w;
        }
    }

    public static void main(String[] args) {
        Exercise215_2 exercise = new Exercise215_2();
        Solution solution = exercise.new Solution();
        int[] nums = new int[] { 3, 2, 1, 5, 6, 4 };

        System.out.println(solution.findKthLargest(nums, 2));
    }
}

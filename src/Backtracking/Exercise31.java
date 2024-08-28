package Backtracking;

import java.util.ArrayList;
import java.util.Arrays;

public class Exercise31 {
    class Solution {
        public void nextPermutation(int[] nums) {
            int i = nums.length - 1;
            while (i > 0 && nums[i] <= nums[i - 1]) {
                i--;
            }

            if (i == 0) {
                Arrays.sort(nums);
                return;
            }
            if (i >= 1) {

                i--;
                int index = nums[i];
                int j = nums.length - 1;
                for (; j > i; j--) {

                    if (nums[j] > index) {
                        break;

                    }
                }
                swap(nums, i, j);
                Arrays.parallelSort(nums, i + 1, nums.length);

            }

        }

        private void swap(int[] nums, int i, int j) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }
    
    public static void main(String[] args) {
        Exercise31 exercise = new Exercise31();
        Solution solution = exercise.new Solution();
        int[] nums = new int[] { 1, 2, 5, 4, 3 };
        solution.nextPermutation(nums);

    }
}

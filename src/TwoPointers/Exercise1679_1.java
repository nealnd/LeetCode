package TwoPointers;

import java.util.Arrays;
public class Exercise1679_1 {
    class Solution {
        public int maxOperations(int[] nums, int k) {
            Arrays.sort(nums);
            int count = 0;
            if (nums[nums.length - 1] < k / 2 || nums[0] > k / 2)
                return 0;
            int i = 0, j = nums.length - 1;
            while (i < j) {
                if (nums[i] + nums[j] > k)
                    j--;
                else if (nums[i] + nums[j] < k)
                    i++;
                else {
                    i++;
                    j++;
                    count++;
                }

            }
            return count;

        }
    }
    public static void main(String[] args) {
        Exercise1679_1 exercise = new Exercise1679_1();
        Solution solution = exercise.new Solution();
        int[] nums = new int[] { 3, 1, 3, 4, 3 };
        System.out.println(solution.maxOperations(nums, 6));
    }
}

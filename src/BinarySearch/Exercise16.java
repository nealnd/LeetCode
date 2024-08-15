package BinarySearch;

import java.util.Arrays;

public class Exercise16 {
    class Solution {
        public int threeSumClosest(int[] nums, int target) {
            Arrays.sort(nums);

            int lo, mid, hi;
           

            int abs, min;
            min = Integer.MAX_VALUE;

            for (lo = 0; lo < nums.length; lo++) {

                mid = lo + 1;
                hi = nums.length - 1;
                while (mid < hi) {
                    int sum = nums[lo] + nums[mid] + nums[hi];
                    abs = target - sum;
                    if (sum > target) {
                        hi--;
                        if (Math.abs(abs) < Math.abs(min))
                            min = abs;
                    } else if (sum < target) {
                        mid++;
                        if (Math.abs(abs) < Math.abs(min))
                            min = abs;

                    } else {
                        min = 0;
                        break;

                    }

                }
            }
            return target-min;
        }
    }

    public static void main(String[] args) {
        Exercise16 exercise = new Exercise16();
        Solution solution = exercise.new Solution();

        int nums[] = { 0,3,97,102,200};
        System.out.println(solution.threeSumClosest(nums, 300));
    }
}

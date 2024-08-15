package BinarySearch;

import java.util.Arrays;
public class Exercise875 {
    class Solution {
        public int minEatingSpeed(int[] piles, int h) {
            long max = 0;
            long sum = 0;
            for (int i = 0; i < piles.length; i++) {
                sum += piles[i];
                max = Math.max(max, piles[i]);
            }
            long low = sum / h;
            while (low <= max) {
                long mid = low + (max - low) / 2;
                int time = 0;
                for (int i = 0; i < piles.length; i++)
                    time += (int) Math.ceil((double) piles[i] / mid);

                if (time > h)
                    low = mid + 1;
                else if (time <= h)
                    max = mid - 1;
            }
            return (int)low;
        }
    }
    public static void main(String[] args) {
        Exercise875 exercise = new Exercise875();
        Solution solution = exercise.new Solution();
        int[] nums = new int[] { 980628391,681530205,734313996,168632541 };
        System.out.println(solution.minEatingSpeed(nums, 819870953));
    }
}

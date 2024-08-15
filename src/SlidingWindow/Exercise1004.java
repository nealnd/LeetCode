package SlidingWindow;
public class Exercise1004 {
    class Solution {
        public int longestOnes(int[] nums, int k) {
            int left = 0, right = 0;
            int surplus = k;
            int max = 0;
            while (right < nums.length) {
                if (nums[right] == 0) {
                    surplus--;
                }
                if (surplus < 0) {
                    max = Math.max(max, right - left);

                    if (nums[left] == 0) {
                        surplus++;

                    }
                    left++;
                }

                right++;
            }
            max = Math.max(max, right - left);
            return max;
        }

    }

    public static void main(String[] args) {
        Exercise1004 exercise = new Exercise1004();
        Solution solution = exercise.new Solution();
        int[] nums = new int[] { 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1 };
        System.out.println(solution.longestOnes(nums, 3));
    }

}

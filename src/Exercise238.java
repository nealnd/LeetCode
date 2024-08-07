import java.util.Arrays;

public class Exercise238 {
    class Solution {
        public int[] productExceptSelf(int[] nums) {
            int[] ans = new int[nums.length];
            Arrays.fill(ans, 1);
            int current = 1;
            for (int i = 0; i < nums.length; i++) {
                ans[i] *= current;
                current *= nums[i];
            }

            current = 1;
            for (int i = nums.length - 1; i >= 0; i--) {
                ans[i] *= current;
                current *= nums[i];
            }
            return ans;
        }
    }

    public static void main(String[] args) {
        Exercise238 exercise = new Exercise238();
        Solution solution = exercise.new Solution();
        int[] nums = new int[] { 1, 2, 3, 4 };
        for (int item : solution.productExceptSelf(nums))
            System.out.println(item);

    }
}

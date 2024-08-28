package DynamicProgramming;


public class Exercise198 {
    class Solution {
        public int rob(int[] nums) {

            int[] db = new int[nums.length + 2];

            int max = 0;
            for (int i = 0; i < nums.length; i++) {
                max = Math.max(max, db[i]);
                db[i + 2] = max + nums[i];

            }
            return Math.max(db[nums.length + 1],db[nums.length]);
        }
    }
        public static void main(String[] args) {
        Exercise198 exercise = new Exercise198();
        Solution solution = exercise.new Solution();

        int[] height = new int[] { 1,2,3,1 };
        System.out.println(solution.rob(height));
    }
}

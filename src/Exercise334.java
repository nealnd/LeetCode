public class Exercise334 {
    class Solution {
        public boolean increasingTriplet(int[] nums) {
            int min1 = Integer.MAX_VALUE;
            int min2 = Integer.MAX_VALUE;

            for (int i = 0; i < nums.length; i++) {

                if (min1 >= nums[i])
                    min1 = nums[i];
                else if (min2 >= nums[i])
                    min2 = nums[i];
                else
                    return true;
            }
            return false;

        }

    }
    public static void main(String[] args) {
        Exercise334 exercise = new Exercise334();
        Solution solution = exercise.new Solution();
        int[] nums = new int[] {20,100,10,12,5,13};
        System.out.println(solution.increasingTriplet(nums));
    }
}

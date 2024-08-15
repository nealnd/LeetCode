package StringAndArray;
public class Exercise27 {
    

    class Solution {
        public int removeElement(int[] nums, int val) {
            int j = 0;
            for (int i = 0; i < nums.length; i++) {
                if (nums[i] == val)
                    continue;
                else {
                    nums[j] = nums[i];
                    j++;
                }
            }
            return j;

        }
    }
    
    public static void main(String[] args) {
        Exercise27 exercise = new Exercise27();
        Solution solution = exercise.new Solution();

        int[] nums = { 0, 1, 2, 2, 3, 0, 4, 2 };
        int j = solution.removeElement(nums, 2);
        for (int i = 0; i < j; i++) {
            
        }



    }

}

package StringAndArray;
import java.util.Arrays;


public class Exercise169_1 {
    class Solution {
        public int majorityElement(int[] nums) {
            Arrays.sort(nums);
            int n = nums.length / 2;

            return nums[n];//assume that the majority element always exists
        }
    }
        public static void main(String[] args) {
        Exercise169_1 exercise = new Exercise169_1();
        Solution solution = exercise.new Solution();

        int nums[] = { 2, 2, 1, 1, 1, 2, 2 };
        System.out.println(solution.majorityElement(nums));
      

    }
}

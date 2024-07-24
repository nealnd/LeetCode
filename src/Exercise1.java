import java.util.HashMap;
import java.util.Map;

public class Exercise1 {
    class Solution {
        public int[] twoSum(int[] nums, int target) {
            Map<Integer, Integer> copy = new HashMap<>();
            for (int i = 0; i < nums.length; i++) {
                int surplus = target - nums[i];
                if (copy.containsKey(surplus))
                    return new int[] { copy.get(surplus), i };//assuming that only one answer exists

                copy.put(nums[i], i);
            }
            return new int[] {};
        }
    }

    public static void main(String[] args) {
        Exercise1 exercise = new Exercise1();
        Solution solution = exercise.new Solution();

        int nums[] = { 2, 7, 11, 15 };
        for (int num : solution.twoSum(nums, 9))
            System.out.println(num);

    }
}

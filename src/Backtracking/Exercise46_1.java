package Backtracking;

import java.util.ArrayList;
import java.util.List;

public class Exercise46_1  {
    class Solution {
        public List<List<Integer>> permute(int[] nums) {
            List<List<Integer>> ans = new ArrayList<>();
            premute(nums, ans, new ArrayList<>());
            return ans;

        }

        private void premute(int[] nums, List<List<Integer>> ans, List<Integer> comb) {
            if (comb.size() == nums.length) {
                ArrayList<Integer> temp = new ArrayList<Integer>(comb);
                ans.add(temp);
                return;
            }

            for (int i = 0; i < nums.length; i++) {
                if (comb.contains(nums[i]))
                    continue;
                    comb.add(nums[i]);
                    premute(nums, ans, comb);
                    comb.remove(comb.size() - 1);
            

            }

        }

    }

    public static void main(String[] args) {
        Exercise46_1 exercise = new Exercise46_1();
        Solution solution = exercise.new Solution();
        int[] nums = new int[] { 1, 2, 3 };
        System.out.println(solution.permute(nums));

    }
}

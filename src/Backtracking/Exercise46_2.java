package Backtracking;

import java.util.ArrayList;
import java.util.List;

public class Exercise46_2 {
    class Solution {
        public List<List<Integer>> permute(int[] nums) {
            List<List<Integer>> ans = new ArrayList<>();
            boolean[] marked = new boolean[nums.length];
            premute(nums, ans, new ArrayList<>(),marked);
            return ans;

        }

        private void premute(int[] nums, List<List<Integer>> ans, List<Integer> comb, boolean[] marked) {
            if (comb.size() == nums.length) {
                ArrayList<Integer> temp = new ArrayList<Integer>(comb);
                ans.add(temp);
                return;
            }

            for (int i = 0; i < nums.length; i++) {
                if (marked[i])
                    continue;
                comb.add(nums[i]);
                marked[i] = true;
                premute(nums, ans, comb, marked);
                marked[i] = false;
                comb.remove(comb.size() - 1);

            }

        }

    }

    public static void main(String[] args) {
        Exercise46_2 exercise = new Exercise46_2();
        Solution solution = exercise.new Solution();
        int[] nums = new int[] { 1, 2, 3,4,5};
        System.out.println(solution.permute(nums));

    }
}

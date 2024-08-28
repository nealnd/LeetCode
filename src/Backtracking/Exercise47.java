package Backtracking;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Exercise47 {
    class Solution {
        public List<List<Integer>> permuteUnique(int[] nums) {

            List<List<Integer>> ans = new ArrayList<>();
            boolean[] marked = new boolean[nums.length];
            Arrays.sort(nums);
            permuteUnique(nums, ans, new ArrayList<>(), marked);
            
            return ans;
        }

        private void permuteUnique(int[] nums, List<List<Integer>> ans, List<Integer> comb, boolean[] marked) {
            if (nums.length == comb.size()) {
                ArrayList<Integer> temp = new ArrayList<>(comb);
                ans.add(temp);
                return;
            }
            for (int i = 0; i < nums.length; i++) {
                if (i < nums.length - 1 && marked[i + 1] == true && nums[i] == nums[i + 1]&&marked[i]==false)
                    continue;
                if (marked[i])
                    continue;
                comb.add(nums[i]);
                marked[i] = true;
                permuteUnique(nums, ans, comb, marked);
                marked[i] = false;
                comb.remove(comb.size() - 1);
            }

        }

    }
        
    public static void main(String[] args) {
        Exercise47 exercise = new Exercise47();
        Solution solution = exercise.new Solution();
        int[] nums = new int[] { 1, 1, 2 };
        System.out.println(solution.permuteUnique(nums));

    }

}


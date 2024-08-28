package Backtracking;

import java.util.ArrayList;
import java.util.List;

public class Exercise39 {
    class Solution {
        public List<List<Integer>> combinationSum(int[] candidates, int target) {
            List<List<Integer>> ans = new ArrayList<>();
            combinationSum(ans, new ArrayList<Integer>(), candidates, target,0);
            return ans;

        }

        private void combinationSum(List<List<Integer>> ans, List<Integer> comb, int[] candidates, int target,int index) {
            if (target < 0)
                return;
            if (target == 0) {
                List<Integer> temp = new ArrayList<>(comb);
                ans.add(temp);
                return;
            }
            for (; index< candidates.length; index++) {
                comb.add(candidates[index]);
                combinationSum(ans, comb, candidates, target - candidates[index],index);
                comb.remove(comb.size()-1);
            }

        }
    }
    public static void main(String[] args) {
        Exercise39 exercise = new Exercise39();
        Solution solution = exercise.new Solution();
        int[] candidates = new int[] { 2, 3,5 };
        System.out.println(solution.combinationSum(candidates, 8));

    }

}

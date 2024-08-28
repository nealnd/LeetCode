package Backtracking;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Exercise40 {
    class Solution {
        public List<List<Integer>> combinationSum2(int[] candidates, int target) {

            List<List<Integer>> ans = new ArrayList<>();
            Arrays.sort(candidates);
            combinationSum2(ans, new ArrayList<Integer>(), candidates, target, 0);
            return ans;
        }

        private void combinationSum2(List<List<Integer>> ans, List<Integer> com, int[] candidates, int target,
                int index) {
            if (target < 0)
                return;
            if (target == 0) {
                List<Integer> temp = new ArrayList<>(com);
                ans.add(temp);
                return;

            }
            for (int i=index; i < candidates.length&&candidates[i]<=target; i++) {
                if (i > index && candidates[i] == candidates[i - 1])
                    continue;
                com.add(candidates[i]);
                combinationSum2(ans, com, candidates, target - candidates[i], i + 1);
                com.remove(com.size() - 1);
            }
        }
    }
    public static void main(String[] args) {
        Exercise40 exercise = new Exercise40();
        Solution solution = exercise.new Solution();
        int[] candidates = new int[] {10,1,2,7,6,1,5 };
        System.out.println(solution.combinationSum2(candidates, 8));

    }

}

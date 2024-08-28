package Backtracking;

import java.util.ArrayList;
import java.util.List;

public class Exercise77 {
    class Solution {
        public List<List<Integer>> combine(int n, int k) {
            List<List<Integer>> ans = new ArrayList<>();
            combine(n, k, ans, new ArrayList<>(), 1);

            return ans;

        }

        private void combine(int n, int k, List<List<Integer>> ans, ArrayList<Integer> comb, int index) {

            if (comb.size() == k) {
                ArrayList<Integer> temp = new ArrayList<>(comb);
                ans.add(temp);
                return;
            }

            for (int i = index; i <= n; i++) {
                comb.add(i);
                combine(n, k, ans, comb, i + 1);
                comb.remove(comb.size() - 1);
            }
        }
    }
    
    public static void main(String[] args) {
        Exercise77 exercise = new Exercise77();
        Solution solution = exercise.new Solution();
        System.out.println(solution.combine(4, 2));

    }

}

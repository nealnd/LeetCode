package Backtracking;

import java.util.ArrayList;
import java.util.List;


public class Exercise216 {
    class Solution {
        public List<List<Integer>> combinationSum3(int k, int n) {

            List<List<Integer>> ans = new ArrayList<>();
           
            combination(ans, new ArrayList<>(), k, n, 1);

            return ans;
        }

        private void combination(List<List<Integer>> ans, ArrayList<Integer> comb, int k, int n, int start) {
            if (comb.size() > k)
                return;
        
            if (comb.size() == k && n == 0) {
                ArrayList<Integer> temp = new ArrayList<>(comb);
                ans.add(temp);
                return;
            }
            for (int i = start; i <=n&&i<= 9; i++) {
                comb.add(i);
                combination(ans, comb, k, n-i,  i+1);
                comb.remove(comb.size() - 1);
            }
        }

    }

        public static void main(String[] args) {
        Exercise216 exercise = new Exercise216();
        Solution solution = exercise.new Solution();
        System.out.println(solution.combinationSum3(3, 9));


    }
}


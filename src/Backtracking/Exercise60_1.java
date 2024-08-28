package Backtracking;

import java.util.ArrayList;

public class Exercise60_1 {
    class Solution {
        public String getPermutation(int n, int k) {
            StringBuilder ans = new StringBuilder();

            getPermutation(ans, new ArrayList<>(), n, k);
            return ans.toString();
        }

        private int getPermutation(StringBuilder ans, ArrayList<Integer> comb, int n, int k) {

            if (k == 0)
                return k;
            if (comb.size() == n && k == 1) {
                for (var item : comb)
                    ans.append(item);
                k--;
                return k;

            }
            if (comb.size() == n && k > 1) {
                k--;
                return k;
            }

            for (int i = 0; i < n; i++) {

                if (comb.contains(i + 1))
                    continue;
                comb.add(i + 1);
                k = getPermutation(ans, comb, n, k);
                if (k == 0)
                    break;
                comb.remove(comb.size() - 1);
            }

            return k;

        }

    }

    public static void main(String[] args) {
        Exercise60_1 exercise = new Exercise60_1();
        Solution solution = exercise.new Solution();
        System.out.println(solution.getPermutation(4, 15));

    }
}

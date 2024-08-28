package Backtracking;

public class Exercise60_2 {
    class Solution {
        public String getPermutation(int n, int k) {
            int[] fact = new int[] { 1, 1, 2, 6, 24, 120, 720, 5040, 40320 };

            StringBuilder seq = new StringBuilder();
            for (int i = 1; i <= n; i++)
                seq.append(Integer.toString(i));

            StringBuilder ans = new StringBuilder();
            k--;
            if (k == 0)
                return ans.toString();

            while (k > 0 && n > 1) {
                int index = k / fact[n - 1];
                k -= index * fact[n - 1];
                ans.append(seq.charAt(index));
                seq.deleteCharAt(index);
                n--;
            }
            ans.append(seq);
            return ans.toString();

        }
    }
    public static void main(String[] args) {
        Exercise60_2 exercise = new Exercise60_2();
        Solution solution = exercise.new Solution();
        System.out.println(solution.getPermutation(4, 9));

    }

}

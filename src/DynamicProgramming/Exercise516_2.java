package DynamicProgramming;

public class Exercise516_2 {
    class Solution {
        public int longestPalindromeSubseq(String s) {
            int n = s.length();
            int[][] dp = new int[n][n];

            //when length of string is 1;
            for (int i = 0; i < n; i++)
                dp[i][i] = 1;

            //when length is 2
            for (int i = 0, j = 1; i < n - 1; i++, j++) {
                if (s.charAt(i) == s.charAt(j))
                    dp[i][j] = 2;
                else
                    dp[i][j] = 1;
            }

            //when length is bigger than 2

            for (int len = 3; len <= n; len++) {
                for (int i = 0, j = len - 1; j < n; i++, j++) {
                    if (s.charAt(i) == s.charAt(j))
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                    else
                        dp[i][j] = Math.max(dp[i][j - 1], dp[i + 1][j]);
                }
            }
            return dp[0][n - 1];
        }
    }

    public static void main(String[] args) {
        Exercise516_2 exercise = new Exercise516_2();
        Solution solution = exercise.new Solution();
        System.out.println(solution.longestPalindromeSubseq("bbbab"));
    }
}

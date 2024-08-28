package DynamicProgramming;

public class Exercise1143 {
    class Solution {
        public int longestCommonSubsequence(String text1, String text2) {
            int row = text1.length();
            int col = text2.length();
            int[][] dp = new int[row + 1][col + 1];
            for (int i = 1; i < row + 1; i++) {
                for (int j = 1; j < col + 1; j++) {
                    if (text1.charAt(i - 1) == text2.charAt(j - 1))
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    else
                        dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
            return dp[row][col];
        }
    }

    public static void main(String[] args) {
        Exercise1143 exercise = new Exercise1143();
        Solution solution = exercise.new Solution();

        System.out.println(solution.longestCommonSubsequence("abccde", "aced"));
    }
}

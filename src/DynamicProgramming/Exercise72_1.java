package DynamicProgramming;

public class Exercise72_1 {
    class Solution {
        public int minDistance(String word1, String word2) {
            int col = word2.length();
            int row = word1.length();

            int[][] dp = new int[row + 1][col + 1];
            for (int i = 0; i < row + 1; i++) {
                for (int j = 0; j < col + 1; j++) {
                    if (i == 0)
                        dp[0][j] = j;
                    else if (j == 0)
                        dp[i][0] = i;

                    else if (word1.charAt(i - 1) != word2.charAt(j - 1)) {
                        dp[i][j] = Math.min(Math.min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1;

                    } else {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                }
            }
            return dp[row][col];
        }
    }
    
    public static void main(String[] args) {
        Exercise72_1 exercise = new Exercise72_1();
        Solution solution = exercise.new Solution();
        System.out.println(solution.minDistance("horse", "ros"));
    }
}

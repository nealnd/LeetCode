package DynamicProgramming;

public class Exercise62_1 {
    class Solution {
        public int uniquePaths(int m, int n) {
            int[][] grid = new int[m][n];
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == 0)
                        grid[0][j] = 1;
                    else if (j == 0)
                        grid[i][0] = 1;
                    else {
                        grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
                    }
                }
            }
            return grid[m - 1][n - 1];

        }
    }
    
    public static void main(String[] args) {
        Exercise62_1 exercise = new Exercise62_1();
        Solution solution = exercise.new Solution();
        System.out.println(solution.uniquePaths(3, 7));
    }
}

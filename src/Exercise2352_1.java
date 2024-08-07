public class Exercise2352_1 {
    class Solution {
        public int equalPairs(int[][] grid) {

            int count = 0;
            for (int i = 0; i < grid.length; i++) {
                for (int j = 0; j < grid.length; j++) {
                    if (grid[i][i] == grid[j][j] && grid[i][j] == grid[i][i]) {
                        int k = 0;
                        for (; k < grid.length; k++) {
                            if (grid[i][k] == grid[k][j])
                                ;
                            else
                                break;

                        }
                        if (k == grid.length)
                            count++;
                    }
                }
            }

            return count;
        }
        
    }
}

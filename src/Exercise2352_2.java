import java.util.HashMap;
import java.util.Map;
import java.util.Arrays;

public class Exercise2352_2 {
    class Solution {
        public int equalPairs(int[][] grid) {
            Map<String, Integer> cnt = new HashMap<>();
            for (int[] row : grid) {
                cnt.merge(Arrays.toString(row), 1, Integer::sum);
            }
            int pairs = 0;
            for (int c = 0, n = grid.length; c < n; ++c) {
                int[] col = new int[n];
                for (int r = 0; r < n; ++r) {
                    col[r] = grid[r][c];
                }
                pairs += cnt.getOrDefault(Arrays.toString(col), 0);
            }
            return pairs;
        }
    }
    public static void main(String[] args) {
        Exercise2352_2 exercise = new Exercise2352_2();
        Solution solution = exercise.new Solution();
        int[][] nums = new int[][] { { 3, 1, 2, 2 }, { 1, 4, 4, 5 },{ 2, 4, 2, 2 },{ 2, 4, 2, 2 } };
        System.out.println(solution.equalPairs(nums));
    }
}

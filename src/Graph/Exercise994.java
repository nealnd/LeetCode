package Graph;

import java.util.Queue;
import java.util.LinkedList;

public class Exercise994 {
    class Solution {
        public int orangesRotting(int[][] grid) {
            Queue<int[]> queue = new LinkedList<>();
            int rows = grid.length - 1;
            int col = grid[0].length - 1;
            int count = 0;
            int number = 0;
            for (int i = 0; i < grid.length; i++) {
                for (int j = 0; j < grid[0].length; j++) {
                    if (grid[i][j] == 2)
                        queue.offer(new int[] { i, j });
                    if (grid[i][j] == 1)
                        count++;
                }
            }
            int[][] directions = new int[][] { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
            while (!queue.isEmpty() && count > 0) {
                number++;
                int size = queue.size();
                while (size > 0 && count > 0) {
                    int[] temp = queue.poll();
                    size--;
                    for (var direction : directions) {
                        int[] x = new int[2];
                        x[0] = temp[0] + direction[0];
                        x[1] = temp[1] + direction[1];

                        if (x[0] < 0 || x[0] > rows || x[1] > col || x[1] < 0 || grid[x[0]][x[1]] == 2)
                            continue;
                        if (grid[x[0]][x[1]] == 1) {
                            grid[x[0]][x[1]] = 2;
                            queue.offer(x);
                            count--;
                        }

                        if (count <= 0)
                            break;
                    }

                }

            }
            if (count > 0)
                return -1;

            return number;

        }
    }

    public static void main(String[] args) {
        Exercise994 exercise = new Exercise994();
        Solution solution = exercise.new Solution();

        int[][] grid = new int[][] { { 2, 1, 1 }, { 1, 1, 0 }, { 0, 1, 1 } };
        System.out.println(solution.orangesRotting(grid));
    }

}

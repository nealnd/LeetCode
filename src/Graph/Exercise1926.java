package Graph;

import java.util.*;

public class Exercise1926 {
    class Solution {
        public int nearestExit(char[][] maze, int[] entrance) {
            int count = 0;
            Queue<coordinate> queue = new LinkedList<>();
            coordinate Entrance = new coordinate(entrance[0], entrance[1]);
            boolean[][] marked = new boolean[maze.length][maze[0].length];
            queue.offer(Entrance);
            while (!queue.isEmpty()) {
                int size = queue.size();
                count++;
                while (size > 0) {

                    coordinate temp = queue.poll();
                    size--;
                    int x = temp.x;
                    int y = temp.y;

                    if (x >= 0 && x < maze.length && y >= 0 && y < maze[0].length && marked[x][y] == false) {
                        marked[x][y] = true;

                        if (maze[x][y] == '+')
                            return -1;
                        if (maze[x][y] == '.' && (x == 0 || x == maze.length - 1 || y == 0 || y == maze[0].length - 1)
                                && !(x == entrance[0] && y == entrance[1]))
                            return count - 1;
                        if (x - 1 >= 0 && maze[x - 1][y] == '.')
                            queue.offer(new coordinate(x - 1, y));
                        if (y - 1 >= 0 && maze[x][y - 1] == '.')
                            queue.offer(new coordinate(x, y - 1));
                        if (x + 1 < maze.length && maze[x + 1][y] == '.')
                            queue.offer(new coordinate(x + 1, y));
                        if (y + 1 < maze[0].length && maze[x][y + 1] == '.')
                            queue.offer(new coordinate(x, y + 1));
                    }

                }
            }
            return -1;

        }

        class coordinate {
            int x;
            int y;

            public coordinate(int x, int y) {
                this.x = x;
                this.y = y;
            }

            public int x() {
                return this.x;
            }

            public int y() {
                return this.y;
            }
        }
    }

    public static void main(String[] args) {
        Exercise1926 exercise = new Exercise1926();
        Solution solution = exercise.new Solution();

        char[][] maze = new char[][] { { '+', '+', '.', '+' }, { '.', '.', '.', '+' }, { '+', '+', '+', '.' } };
        int[] entrance = new int[] { 1, 2 };
        System.out.println(solution.nearestExit(maze, entrance));
    }
}

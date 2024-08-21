package Graph;

import java.util.Queue;
import java.util.LinkedList;

public class Exercise1466 {
    class Solution {
        public int minReorder(int n, int[][] connections) {
            boolean[] marked = new boolean[n];

            Queue<Integer>[] adj = new Queue[n];
            for (int i = 0; i < n; i++)
                adj[i] = new LinkedList<>();
            for (int i = 0; i < n && i < connections.length; i++) {
                int index = connections[i][0];
                adj[index].offer(connections[i][1]);//real edges
                adj[connections[i][1]].offer(-index);//the fake edges that don't exist but enable us to visit all the points
            }

            return dfs(adj, 0, marked);

        }

        private int dfs(Queue<Integer>[] adj, int index, boolean[] marked) {
            int count = 0;

            marked[index] = true;

            for (int item : adj[index]) {
                if (!marked[Math.abs(item)]) {
                    if (item > 0)
                        count += dfs(adj, Math.abs(item), marked) + 1;//all the edges away from 0 and its connected points
                    else
                        count += dfs(adj, Math.abs(item), marked);//all the edges toward 0 and its connected points
                }

            }
            return count;
        }
    }

    public static void main(String[] args) {
        Exercise1466 exercise = new Exercise1466();
        Solution solution = exercise.new Solution();
        int[][] connections = new int[][] { { 0, 1 }, { 1, 3 }, { 2, 3 }, { 4, 0 }, { 4, 5 } };
        // int[][] connections = new int[][] { { 1, 2 }, { 2, 0 } };

        System.out.println(solution.minReorder(6, connections));
    }

}

package Graph;

public class Exercise547_1 {
    class Solution {
        public int findCircleNum(int[][] isConnected) {
            boolean[] marked = new boolean[isConnected.length];
            int count = 0;
            for (int i = 0; i < marked.length; i++) {
                if (marked[i] == false) {
                    count++;
                    findCircleNum(isConnected, i, 0, marked);
                }
            }
            return count;

        }

        private void findCircleNum(int[][] isConnected, int row, int col, boolean[] marked) {
            if (row >= isConnected.length || col >= isConnected.length)
                return;
            marked[row] = true;
            if ((isConnected[row][col] == 1) && marked[col]==false){
                findCircleNum(isConnected, col, 0, marked);
            }
            findCircleNum(isConnected, row, col + 1, marked);
        }

    }

    public static void main(String[] args) {
        Exercise547_1 exercise = new Exercise547_1();
        Solution solution = exercise.new Solution();

        int[][] isConnected = new int[][] { { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
                { 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }, { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                { 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0 },
                { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }, { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                { 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
                { 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0 },
                { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
                { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 }, { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
                { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 } };
            System.out.println(solution.findCircleNum(isConnected));

    }
}

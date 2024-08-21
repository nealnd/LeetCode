package Graph;

public class Exercise547_2 {
    class Solution {
        public int findCircleNum(int[][] isConnected) {
            QuickUnionUF uf = new QuickUnionUF(isConnected.length);
            for (int i = 0; i < isConnected.length; i++) {
                for (int j = 0; j < isConnected.length; j++) {
                    if (isConnected[i][j] == 1)
                        uf.union(i, j);
                }

            }
            return uf.count;
        }

        private class QuickUnionUF {
            private int[] parent;
            private int count;

            public QuickUnionUF(int n) {
                parent = new int[n];
                count = n;
                for (int i = 0; i < n; i++) {
                    parent[i] = i;
                }
            }
            
            public int find(int p) {
                while(p!=parent[p])
                    p = parent[p];
                return p;
            }
            public void union(int p, int q) {
                int rootp = find(p);
                int rootq = find(q);
                if (rootp == rootq)
                    return;
                parent[rootp] = rootq;
                count--;
            }
        }
}
public static void main(String[] args) {
    Exercise547_2 exercise = new Exercise547_2();
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

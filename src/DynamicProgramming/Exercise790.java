package DynamicProgramming;

public class Exercise790 {
    class Solution {
        public int numTilings(int n) {

            long[] d = new long[1001];
            long[] t = new long[1001];
            int modulo = 1000000007;
            d[0] = 0;
            d[1] = 1;
            d[2] = 2;
            t[0] = 0;
            t[1] = 1;
            t[2] = 2;
            for (int i = 3; i <= n; i++) {
                d[i] = (d[i - 1] + d[i - 2] + 2 * t[i - 2]) % modulo;
                t[i] = (t[i - 1] + d[i - 1]) % modulo;
            }

            return (int) d[n];

        }
    }
    
    public static void main(String[] args) {
        Exercise790 exercise = new Exercise790();
        Solution solution = exercise.new Solution();


        System.out.println(solution.numTilings(4));
    }
}

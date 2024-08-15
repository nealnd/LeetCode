package StringAndArray;
public class Exercise70 {
    class Solution {
        public int climbStairs(int n) {
            int[] ways = new int[n + 1];
            ways[1] = 1;
            if (n > 1)
                ways[2] = 2;
            if (n > 2) {
                for (int i = 3; i < n + 1; i++) {
                    ways[i] = ways[i - 2] + ways[i - 1];
                }
            }
    
            return ways[n];

        }

    }
    public static void main(String[] args) {
        Exercise70 exercise = new Exercise70();
        Solution solution = exercise.new Solution();
        System.out.println(solution.climbStairs(45));
    }

}

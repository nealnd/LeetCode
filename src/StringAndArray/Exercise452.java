package StringAndArray;

import java.util.Arrays;

public class Exercise452 {
    class Solution {
        public int findMinArrowShots(int[][] points) {
            Arrays.sort(points, (a, b) -> Integer.compare(a[1], b[1]));
            int lo = points[0][0];
            int hi = points[0][1];
            int count = 1;
            for (int i = 1; i < points.length; i++) {
                if (points[i][0] <= hi)
                    lo = (lo < points[i][0] ? points[i][0] : lo);

                else {
                    count++;
                    lo = points[i][0];
                    hi = points[i][1];
                }

            }
            return count;
        }
    }
    public static void main(String[] args) {
        Exercise452 exercise = new Exercise452();
        Solution solution = exercise.new Solution();
        int[][] nums = new int[][] { { 10, 16 }, { 2, 8 }, { 1, 6 }, { 7, 12 } };
        System.out.println(solution.findMinArrowShots(nums));
    }
}

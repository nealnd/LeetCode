package StringAndArray;

import java.util.Arrays;
import java.util.Comparator;

public class Exercise435_1 {
    class Solution {
        public int eraseOverlapIntervals(int[][] intervals) {
            Arrays.sort(intervals, new Comparator<int[]>() {
                public int compare(int[] a, int[] b) {
                    if (a[0] < b[0])
                        return -1;
                    else if (a[0] == b[0] && a[1] < b[1])
                        return -1;
                    else if (a[0] == b[0] && a[1] > b[1])
                        return 1;
                    else if (a[0] > b[0])
                        return 1;
                    else
                        return 0;

                }

            });
            int count = 0;
            int lo = intervals[0][0];
            int hi = intervals[0][1];

            for (int i = 1; i < intervals.length; i++) {

                if (intervals[i][0] >= lo && intervals[i][1] <= hi) {
                    lo = intervals[i][0];
                    hi = intervals[i][1];
                    count++;
                } else if (intervals[i][0] >= lo && intervals[i][0] < hi && intervals[i][1] > hi) {
                    count++;
                } else {
                    lo = intervals[i][0];
                    hi = intervals[i][1];

                }

            }
            return count;
        }
    }
    public static void main(String[] args) {
        Exercise435_1 exercise = new Exercise435_1();
        Solution solution = exercise.new Solution();
        int[][] nums = new int[][] { { 0, 2 }, { 1, 3 }, { 2, 4 }, { 3, 5 }, { 4, 6 } };
        System.out.println(solution.eraseOverlapIntervals(nums));
    }

}

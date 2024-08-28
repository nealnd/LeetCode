package StringAndArray;

import java.util.Arrays;


public class Exercise435_2 {

    class Solution {
        public int eraseOverlapIntervals(int[][] intervals) {
            int n = intervals.length;
            Arrays.sort(intervals, (a, b) -> Integer.compare(a[1], b[1]));

            int prev = 0;
            int count = 1;

            for (int i = 1; i < n; i++) {
                if (intervals[i][0] >= intervals[prev][1]) {
                    prev = i;
                    count++;
                }
            }
            return n - count;
        }
    }
        public static void main(String[] args) {
            Exercise435_2 exercise = new Exercise435_2();
            Solution solution = exercise.new Solution();
            int[][] nums = new int[][] { { 0, 2 }, { 1, 3 }, { 2, 4 }, { 3, 5 }, { 4, 6 } };
            System.out.println(solution.eraseOverlapIntervals(nums));
        }

    }

package Backtracking;

import java.util.ArrayList;
import java.util.Arrays;

public class Exercise2212_2 {
    class Solution {
        int sum = 0;
        int[] ans = new int[12];

        public int[] maximumBobPoints(int numArrows, int[] aliceArrows) {

            maximumBobPoints(numArrows, aliceArrows, 11, new int[aliceArrows.length], 0);
            return ans;

        }

        private void maximumBobPoints(int numArrows, int[] aliceArrows, int index, int[] comb, int points) {
            if (index < 0 || numArrows <= 0) {
                if (numArrows > 0)
                    comb[0] += numArrows;
                if (points > sum) {
                    this.ans = comb.clone();
                    sum = points;

                }
                return;
            }
            if (numArrows >= aliceArrows[index] + 1) {
                comb[index] = aliceArrows[index] + 1;
                maximumBobPoints(numArrows - aliceArrows[index] - 1, aliceArrows, index - 1, comb, points + index);
                comb[index] = 0;
            }

            maximumBobPoints(numArrows, aliceArrows, index - 1, comb, points);
            comb[index] = 0;

        }
    }

    public static void main(String[] args) {
        Exercise2212_2 exercise = new Exercise2212_2();
        Solution solution = exercise.new Solution();
        int[] aliceArrows = new int[] { 1, 1, 0, 1, 0, 0, 2, 1, 0, 1, 2, 0 };
        for (var item : solution.maximumBobPoints(9, aliceArrows))
            System.out.println(item);

    }
}

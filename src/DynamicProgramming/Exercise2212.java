package DynamicProgramming;

public class Exercise2212 {
    class Solution {
        public int[] maximumBobPoints(int numArrows, int[] aliceArrows) {
            int[][] win = new int[aliceArrows.length][numArrows + 1];
            int[][] lost = new int[aliceArrows.length][numArrows + 1];



            for (int i = 1; i < aliceArrows.length; i++) {
                for (int j = 0; j < numArrows + 1; j++) {

                    win[i][0] = 0;
                    lost[i][0] = 0;
                    win[0][j] = 0;
                    lost[i][j] = Math.max(win[i - 1][j], lost[i - 1][j]);
                    if (j > aliceArrows[i])
                        win[i][j] = Math.max(win[i - 1][j - aliceArrows[i] - 1] + i,
                                lost[i - 1][j - aliceArrows[i] - 1] + i);
                    else {
                        win[i][j] = Math.max(win[i - 1][j], lost[i - 1][j]);
                    }
                }
            }
            int[] ans = new int[aliceArrows.length];
            for (int i = aliceArrows.length - 1; i >= 0; i--) {

                if (win[i][numArrows] > lost[i][numArrows] && numArrows > 0) {
                    ans[i] = aliceArrows[i] + 1;
                    numArrows -= aliceArrows[i] + 1;
                } else
                    ans[i] = 0;
            }
            if (numArrows > 0)
                ans[0] = numArrows;

            return ans;
        }
    }

    public static void main(String[] args) {
        Exercise2212 exercise = new Exercise2212();
        Solution solution = exercise.new Solution();
        int[] aliceArrows = new int[] { 1, 1, 0, 1, 0, 0, 2, 1, 0, 1, 2, 0 };

       for(var item:solution.maximumBobPoints(9, aliceArrows)) 
       System.out.println(item);
    }

}

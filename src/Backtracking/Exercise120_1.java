package Backtracking;

import java.util.List;
import java.util.ArrayList;

public class Exercise120_1 {
    class Solution {
        public int minimumTotal(List<List<Integer>> triangle) {

            int[][] dp = new int[triangle.size()][triangle.getLast().size()];
            dp[0][0] = triangle.get(0).get(0);
            for (int i = 1; i < triangle.size(); i++) {
                for (int j = 0; j < i + 1; j++) {
                    if (j > 0&&j<i)
                        dp[i][j] = Math.min(dp[i - 1][j] + triangle.get(i).get(j),
                                dp[i - 1][j - 1] + triangle.get(i).get(j));
                    else if(j==0)
                        dp[i][j] = dp[i - 1][j] + triangle.get(i).get(j);
                    else 
                    dp[i][j] = dp[i - 1][j - 1] + triangle.get(i).get(j);
                }
            }
            int min = Integer.MAX_VALUE;

            for (int i = 0; i < dp[triangle.size() - 1].length; i++) {
                if (dp[triangle.size() - 1][i] < min)
                    min = dp[triangle.size() - 1][i];
            }

            return min;
        }

    }

    public static void main(String[] args) {
        Exercise120_1 exercise = new Exercise120_1();
        Solution solution = exercise.new Solution();
        List<Integer>l1=new ArrayList<>(List.of(2));
        List<Integer>l2=new ArrayList<>(List.of(3,4));
        List<Integer>l3=new ArrayList<>(List.of(6,5,7));
        List<Integer>l4=new ArrayList<>(List.of(4,1,8,3));
        List<List<Integer>> triangle = new ArrayList<>(List.of(l1, l2, l3, l4));
        System.out.println(solution.minimumTotal(triangle));
        
        


    }


}
package DynamicProgramming;

public class Exercise123 {
    class Solution {
        public int maxProfit(int[] prices) {
            int[][] buy = new int[prices.length][2];
            int[][] sell = new int[prices.length][2];
            buy[0][0] = -prices[0];
            buy[0][1] = -prices[0];
    
            for (int i = 1; i < prices.length; i++) {
                buy[i][0] = Math.max(buy[i - 1][0], -prices[i]);
                sell[i][0] = Math.max(sell[i - 1][0], buy[i - 1][0] + prices[i]);
    
                buy[i][1] = Math.max(sell[i - 1][0] - prices[i], buy[i - 1][1]);
                sell[i][1] = Math.max(buy[i - 1][1] + prices[i], sell[i - 1][1]);
    
            }
    
            return sell[prices.length - 1][1];
        }
    }
    
    public static void main(String[] args) {
        Exercise123 exercise = new Exercise123();
        Solution solution = exercise.new Solution();
        int[] prices = new int[] { 3,3,5,0,0,3,1,4 };
        System.out.println(solution.maxProfit(prices));
    }
    }


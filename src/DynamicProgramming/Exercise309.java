package DynamicProgramming;

public class Exercise309 {
    class Solution {
        public int maxProfit(int[] prices) {
            int[] buy = new int[prices.length];
            int[] sell = new int[prices.length];
            buy[0] = -prices[0];
            if (prices.length > 1) {
                buy[1] = Math.max(buy[0], -prices[1]);
                sell[1] = Math.max(sell[0], buy[0] + prices[1]);
                for (int i = 2; i < prices.length; i++) {
                    buy[i] = Math.max(buy[i - 1], sell[i - 2] - prices[i]);
                    sell[i] = Math.max(sell[i - 1], buy[i - 1] + prices[i]);
                }
            }
            return sell[prices.length - 1];
        }
    }

    public static void main(String[] args) {
        Exercise309 exercise = new Exercise309();
        Solution solution = exercise.new Solution();
        int[] prices = new int[] { 7,1,5,3,6,4 };
        System.out.println(solution.maxProfit(prices));
    }
}

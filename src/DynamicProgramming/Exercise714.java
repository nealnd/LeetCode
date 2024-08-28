package DynamicProgramming;

public class Exercise714 {
    class Solution {
        public int maxProfit(int[] prices, int fee) {
            int[] buy = new int[prices.length];
            int[] sell = new int[prices.length];
            buy[0] = -prices[0];
            for (int i = 1; i < prices.length; i++) {
                buy[i] = Math.max(buy[i - 1], sell[i - 1] - prices[i]);
                sell[i] = Math.max(sell[i - 1], buy[i - 1] + prices[i] - fee);
            }

            return sell[prices.length - 1];
        }

    }
    public static void main(String[] args) {
        Exercise714 exercise = new Exercise714();
        Solution solution = exercise.new Solution();
        int[] prices = new int[] { 1, 3, 2, 8, 4, 9 };
        System.out.println(solution.maxProfit(prices, 2));
    }
}

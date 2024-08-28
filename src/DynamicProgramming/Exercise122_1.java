package DynamicProgramming;

public class Exercise122_1 {
    class Solution {
        public int maxProfit(int[] prices) {
            int n = prices.length;
            int[] buy = new int[n];
            int[] sell = new int[n];
            buy[0] = -prices[0];
            for (int i = 1; i < n; i++) {
                buy[i] = Math.max(buy[i - 1], sell[i - 1] - prices[i]);
                sell[i] = Math.max(sell[i - 1], buy[i - 1] + prices[i]);
            }
            return sell[n - 1];
        }
    }
    
    public static void main(String[] args) {
        Exercise122_1 exercise = new Exercise122_1();
        Solution solution = exercise.new Solution();
        int[] prices = new int[] { 7,1,5,3,6,4 };
        System.out.println(solution.maxProfit(prices));
    }
}

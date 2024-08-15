package StringAndArray;
public class Exercise1456_1 {
    class Solution {
        public int maxVowels(String s, int k) {

            int[] dp = new int[s.length() + 1];
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) == 'a' || s.charAt(i) == 'e' || s.charAt(i) == 'i' || s.charAt(i) == 'o'
                        || s.charAt(i) == 'u') {
                    dp[i + 1] = 1;
                }
            }
            for (int i = 1; i < dp.length; i++)
                dp[i] += dp[i - 1];

            int max = 0;
            for (int i = k; i < dp.length; i++) {
                if (max < dp[i] - dp[i - k])
                    max = dp[i] - dp[i - k];
            }
            return max;
        }
    }
    public static void main(String[] args) {
        Exercise1456_1 exercise = new Exercise1456_1();
        Solution solution = exercise.new Solution();
        String s = "leetcode";
        System.out.println(solution.maxVowels(s, 3));
    }
}

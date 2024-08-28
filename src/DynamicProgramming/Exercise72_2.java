package DynamicProgramming;


public class Exercise72_2 {
    class Solution {
        public int minDistance(String word1, String word2) {
            if(word1.length() < word2.length()) return minDistance(word2,word1);
            int[] dp = new int[word2.length() + 1];
            for(int i = 0;i<dp.length;i++) dp[i] = i;           //initialize, compare "" with word2
            for(int i = 0;i<word1.length();i++){
                int[] next = new int[word2.length() + 1];       
                next[0] = i+1;                                  //initialize compare word1 with ""
                for(int j = 0;j< word2.length();j++){
                    if(word1.charAt(i) == word2.charAt(j)) next[j+1] = dp[j];
                    else next[j+1] = Math.min(next[j],Math.min(dp[j],dp[j+1])) + 1;
                }
                dp = next;
            }
            return dp[word2.length()];
        }

    }
    
    public static void main(String[] args) {
        Exercise72_2 exercise = new Exercise72_2();
        Solution solution = exercise.new Solution();
        System.out.println(solution.minDistance("horse", "ros"));
    }
}

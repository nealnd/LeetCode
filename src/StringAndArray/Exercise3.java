package StringAndArray;


public class Exercise3 {

    class Solution {

        public int lengthOfLongestSubstring(String s) {
            int i = 0, j = 0;
            int k;
            int maxlength = 0;
            if (s.length() == 0)
                return 0;
            while (true) {


                for (j=i+1; j < s.length(); j++) {
                    
                    String temp = s.subSequence(i, j).toString();
                    if (temp.contains(String.valueOf(s.charAt(j)))) {

                        k = i+temp.indexOf(s.charAt(j));
                        maxlength = Math.max(maxlength, j - i);
                        i = k + 1;

                    }
                }

                if (j == s.length())
                {
                    maxlength = Math.max(maxlength, j - i);
                    break;
                }
                
            }
            if (i == 0)
                return s.length();

            return maxlength;
        }

    }

    public static void main(String[] args) {
        Exercise3 exercise = new Exercise3();
        Solution solution = exercise.new Solution();
        String s = "aab";
        System.out.println(solution.lengthOfLongestSubstring(s));

    }
}

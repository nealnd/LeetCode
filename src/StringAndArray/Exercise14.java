package StringAndArray;
import java.util.Arrays;

public class Exercise14 {
    class Solution {
        public String longestCommonPrefix(String[] strs) {
            String s = "";
            Arrays.sort(strs);
            for (int i = 0; i < Math.min(strs[0].length(), strs[strs.length - 1].length()); i++) {
                if (strs[0].charAt(i) == strs[strs.length - 1].charAt(i))
                    s=s.concat(Character.toString(strs[0].charAt(i)));
                else
                    break;
            }
            return s;
        }
    }
    
    public static void main(String[] args) {
        Exercise14 exercise = new Exercise14();
        Solution solution = exercise.new Solution();
        String[] strs = { "flower", "flow", "flight" };
        System.out.println(solution.longestCommonPrefix(strs));

    }
}

package Backtracking;

import java.util.LinkedList;
import java.util.List;

public class Exercise17_2 {
    class Solution {
        public List<String> letterCombinations(String digits) {
            LinkedList<String> ans = new LinkedList<String>();
            if (digits.isEmpty())
                return ans;
            String[] mapping = new String[] { "0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
            ans.add("");
            while (ans.peek().length() != digits.length()) {
                String remove = ans.remove();
                String map = mapping[digits.charAt(remove.length()) - '0'];
                for (char c : map.toCharArray()) {
                    ans.addLast(remove + c);
                }
            }
            return ans;
        }
    }

    public static void main(String[] args) {
        Exercise17_2 exercise = new Exercise17_2();
        Solution solution = exercise.new Solution();
        System.out.println(solution.letterCombinations("234"));

    }
}

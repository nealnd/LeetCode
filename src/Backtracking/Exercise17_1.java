package Backtracking;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class Exercise17_1 {
    class Solution {
        public List<String> letterCombinations(String digits) {
            HashMap<Character, Character[]> map = new HashMap<>();
            map.put('2', new Character[] { 'a', 'b', 'c' });
            map.put('3', new Character[] { 'd', 'e', 'f' });
            map.put('4', new Character[] { 'g', 'h', 'i' });
            map.put('5', new Character[] { 'j', 'k', 'l' });
            map.put('6', new Character[] { 'm', 'n', 'o' });
            map.put('7', new Character[] { 'p', 'q', 'r', 's' });
            map.put('8', new Character[] { 't', 'u', 'v' });
            map.put('9', new Character[] { 'w', 'x', 'y', 'z' });
            
            List<String> ans = new ArrayList<>();
            if (digits == "")
                return ans;
            letterCombinations(ans, new StringBuilder(), digits, 0, map);
            return ans;

        }

        private void letterCombinations(List<String> ans, StringBuilder comb, String digits, int start,
                HashMap<Character, Character[]> map) {
            
            if (comb.length() == digits.length()) {
                String temp = new String(comb.toString());
                ans.add(temp);
                return;
            }

            for (int i = 0; i < map.get(digits.charAt(start)).length;i++) {
                comb.append(map.get(digits.charAt(start))[i]);
                letterCombinations(ans, comb, digits, start + 1, map);
                comb.deleteCharAt(comb.length() - 1);


            }

        }
    }

    public static void main(String[] args) {
        Exercise17_1 exercise = new Exercise17_1();
        Solution solution = exercise.new Solution();
        System.out.println(solution.letterCombinations(""));

    }
}

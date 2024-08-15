package StackAndQueue;
import java.util.Stack;

public class Exercise394_2 {

    class Solution {
        public String decodeString(String s) {
            Stack<Integer> intStack = new Stack<>();//store the number
            Stack<StringBuilder> strStack = new Stack<>();//store the string
            StringBuilder cur = new StringBuilder();
            int k = 0;
            for (char ch : s.toCharArray()) {
                if (Character.isDigit(ch)) {
                    k = k * 10 + ch - '0';
                } else if (ch == '[') {
                    intStack.push(k);
                    strStack.push(cur);
                    cur = new StringBuilder();
                    k = 0;
                } else if (ch == ']') {
                    StringBuilder tmp = cur;
                    cur = strStack.pop();
                    for (k = intStack.pop(); k > 0; --k)
                        cur.append(tmp);
                } else
                    cur.append(ch);
            }
            return cur.toString();
        }
    }

    public static void main(String[] args) {
        Exercise394_2 exercise = new Exercise394_2();
        Solution solution = exercise.new Solution();
        String s = "2[abc]3[cd]ef";
        System.out.println(solution.decodeString(s));
    }

}

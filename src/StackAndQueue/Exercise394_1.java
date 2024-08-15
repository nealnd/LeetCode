package StackAndQueue;
import java.util.Stack;

public class Exercise394_1 {
    class Solution {
        public String decodeString(String s) {

            Stack<Character> stack = new Stack<>();
            Stack<Character> temp = new Stack<>();
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) != ']')
                    stack.push(s.charAt(i));
                if (s.charAt(i) == ']') {
                    while (stack.peek() != '[')
                        temp.push(stack.pop());
                    stack.pop();
                    int count = 0;
                    int j = 0;
                    while(!stack.isEmpty()&&(stack.peek()-'0')<=9&&(stack.peek()-'0')>=0)
                    {

                        j += (stack.pop() - '0') * Math.pow(10, count++);
                    }
                    while (j >= 1) {
                        for (int k = temp.size() - 1; k >= 0; k--)
                            stack.push(temp.get(k));
                        j--;

                    }
                    temp.clear();
                }

            }
            StringBuilder ans = new StringBuilder();
            for (int i = 0; i < stack.size(); i++) {
                ans.append(stack.get(i));
            }
            return ans.toString();
           
        }
    }

    public static void main(String[] args) {
        Exercise394_1 exercise = new Exercise394_1();
        Solution solution = exercise.new Solution();
        String s = "2[abc]3[cd]ef";
        System.out.println(solution.decodeString(s));
    }
    
}

package StackAndQueue;
import java.util.List;
import java.util.Stack;

public class Exercise20 {
    class Solution {
        public boolean isValid(String s) {
            Stack<Character> stack = new Stack<>();
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) == '(' || s.charAt(i) == '[' || s.charAt(i) == '{')
                    stack.push(s.charAt(i));
                else {
                    if (stack.isEmpty())
                        return false;
                    if (s.charAt(i) == ')' && stack.peek() == '(')
                        stack.pop();
                    else if (s.charAt(i) == ']' && stack.peek() == '[')
                        stack.pop();
                    else if (s.charAt(i) == '}' && stack.peek() == '{')
                        stack.pop();
                    else
                        return false;

                }

            }
            return stack.isEmpty();
        }

    }
        public static void main(String[] args) {
        Exercise20 exercise = new Exercise20();
        Solution solution = exercise.new Solution();

        String s = "]";
        System.out.println(solution.isValid(s));
        }

    }


package StackAndQueue;

import java.util.Stack;

public class Exercise739_2 {
    class Solution {

        public int[] dailyTemperatures(int[] temperatures) {
            Stack<Integer> stack = new Stack<>();
            int[] ret = new int[temperatures.length];
            for (int i = 0; i < temperatures.length; i++) {
                while (!stack.isEmpty() && temperatures[i] > temperatures[stack.peek()]) {
                    int idx = stack.pop();
                    ret[idx] = i - idx;
                }
                stack.push(i);
            }
            return ret;
        }

    }

    public static void main(String[] args) {
        Exercise739_2 exercise = new Exercise739_2();
        Solution solution = exercise.new Solution();
        int[] temperatures = new int[] { 73, 74, 75, 71, 69, 72, 76, 73 };
        for (var item : solution.dailyTemperatures(temperatures))
            System.out.println(item);
    }
}

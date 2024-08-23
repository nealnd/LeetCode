package StackAndQueue;

import java.util.Stack;

public class Exercise739_1 {
    class Solution {
        public int[] dailyTemperatures(int[] temperatures) {
            Stack<int[]> stack = new Stack<>();

            int[] count = new int[temperatures.length];
            for (int i = 0; i < temperatures.length; i++) {

                while (!stack.isEmpty() && temperatures[i] > stack.peek()[0]) {

                    count[stack.peek()[1]] = i - stack.peek()[1];
                    stack.pop();
                }
                stack.push(new int[] { temperatures[i], i });

            }
            return count;
        }

    }

    public static void main(String[] args) {
        Exercise739_1 exercise = new Exercise739_1();
        Solution solution = exercise.new Solution();
        int[] temperatures = new int[] { 73, 74, 75, 71, 69, 72, 76, 73 };
        for (var item : solution.dailyTemperatures(temperatures))
            System.out.println(item);
    }
}

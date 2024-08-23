package StackAndQueue;

public class Exercise739_3 {
    class Solution {
        public int[] dailyTemperatures(int[] temperatures) {
            int[] stack = new int[temperatures.length];
            int top = -1;
            int[] ret = new int[temperatures.length];
            for (int i = 0; i < temperatures.length; i++) {
                while (top > -1 && temperatures[i] > temperatures[stack[top]]) {
                    int idx = stack[top--];
                    ret[idx] = i - idx;
                }
                stack[++top] = i;
            }
            return ret;
        }
    }
    
    public static void main(String[] args) {
        Exercise739_3 exercise = new Exercise739_3();
        Solution solution = exercise.new Solution();
        int[] temperatures = new int[] { 73, 74, 75, 71, 69, 72, 76, 73 };
        for (var item : solution.dailyTemperatures(temperatures))
            System.out.println(item);
    }
}

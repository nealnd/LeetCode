package StackAndQueue;

import java.util.Stack;

public class Exercise901 {

    class StockSpanner {

        Stack<int[]> stack;
        int count;

        public StockSpanner() {
            stack = new Stack<>();
            count = 0;

        }

        public int next(int price) {

            while (!stack.isEmpty() && stack.peek()[0] <= price) {
                stack.pop();

            }

            int temp = count - (stack.isEmpty() ? -1 : stack.peek()[1]);

            stack.push(new int[] { price, count++ });
            return temp;

        }
    }
}

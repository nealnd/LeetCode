package TwoPointers;
public class Exercise11 {
    class Solution {
        public int maxArea(int[] height) {
            int i = 0, j = height.length - 1;
            int area = Integer.MIN_VALUE;

            while (i < j) {
                int temp = Math.min(height[i], height[j]) * (j - i);
                if (area < temp)
                    area = temp;
                if (height[i] <= height[j])
                    i++;
                else
                    j--;

            }
            return area;
        }
    }

    public static void main(String[] args) {
        Exercise11 exercise = new Exercise11();
        Solution solution = exercise.new Solution();

        int[] height = new int[] { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
        System.out.println(solution.maxArea(height));
    }
}

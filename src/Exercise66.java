public class Exercise66 {
    class Solution {
        public int[] plusOne(int[] digits) {
            int i = digits.length - 1;
            for (; i >= 0; i--) {
                if (digits[i] == 9) {
                    digits[i] = 0;
                } else {
                    digits[i]++;
                    return digits;
                }
            }
            digits = new int[digits.length + 1];
            digits[0] = 1;//remember the default nunber is 0 after initialized
            return digits;
        }
    }
    
    public static void main(String[] args) {
        Exercise66 exercise = new Exercise66();
        Solution solution = exercise.new Solution();

        int[] digits = { 9, 9 };
        int[] ans = solution.plusOne(digits);
        for (int i = 0; i < ans.length; i++) {
            System.out.println(ans[i]);
        }

    }

}

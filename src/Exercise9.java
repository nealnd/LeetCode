public class Exercise9 {

    class Solution {
        public boolean isPalindrome(int x) {
            String str = Integer.toString(x);
            for (int i = 0; i < str.length() / 2; i++) {
                if (str.charAt(i) == str.charAt(str.length() - i - 1))
                    continue;
                else
                    return false;
            }
            return true;

        }
    }

    public static void main(String[] args) {
        Exercise9 exercise = new Exercise9();
        Solution solution = exercise.new Solution();

        int x = -121;
        System.out.println(solution.isPalindrome(x));

    }
}

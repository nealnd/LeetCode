public class Exercise2390_1 {
    class Solution {
        public String removeStars(String s) {
            StringBuilder sb = new StringBuilder(s);
            int i = 0, j = 0;
            for (; j < sb.length(); j++) {
                if (sb.charAt(j) == '*' && j - 1 >= 0) {
                    sb.delete(j - 1, j + 1);
                    j = j - 2;
                }
            }
            return sb.toString();
        }
    }
    
    public static void main(String[] args) {
        Exercise2390_1 exercise = new Exercise2390_1();
        Solution solution = exercise.new Solution();
        String s = "leet**cod*e";
        System.out.println(solution.removeStars(s));
    }
}

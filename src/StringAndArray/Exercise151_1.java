package StringAndArray;
public class Exercise151_1 {

    class Solution {
        public String reverseWords(String s) {
            StringBuilder ans = new StringBuilder();

            int i = s.length() - 1;
            int j = s.length() - 1;
            while (true) {
                if (i < 0||j<0)
                    break;
                while (s.charAt(j) == ' ' && s.charAt(i) == ' ') {
                    i--;
                    j--;
                    if (i < 0)
                        break;
                }
                if (i >= 0 && j >= 0) {
                    while (s.charAt(j) != ' ' && s.charAt(i) != ' ') {
                        j--;
                        if (j < 0)
                            break;
                    }
                }
                ans.append(s.substring(j + 1, i + 1) + " ");
                i = j;

            }

            return ans.toString().trim();

        }

    }

    public static void main(String[] args) {
        Exercise151_1 exercise = new Exercise151_1();
        Solution solution = exercise.new Solution();
        String s = "t ";

        System.out.println(solution.reverseWords(s));
    }
}

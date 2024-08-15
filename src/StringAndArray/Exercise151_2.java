package StringAndArray;
public class Exercise151_2 {

    class Solution {
        public String reverseWords(String s) {
            String[] str = s.trim().split("\\s+");//split using one or many whitespaces

            String out = "";

            for (int i = str.length - 1; i > 0; i--) {

                out += str[i] + " ";
            }

            return out + str[0];
        }
    }

    public static void main(String[] args) {
        Exercise151_2 exercise = new Exercise151_2();
        Solution solution = exercise.new Solution();
        String s = "a good    example";

        System.out.println(solution.reverseWords(s));
    }
}

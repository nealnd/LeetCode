public class Exercise28 {
    class Solution {
        public int strStr(String haystack, String needle) {

            return haystack.indexOf(needle);

        }

    }
    
    public static void main(String[] args) {
        Exercise28 exercise = new Exercise28();
        Solution solution = exercise.new Solution();
        String s1 = "adfghj";
        String s2 = "fgh";
        System.out.println(solution.strStr(s1, s2));
       
    }
}

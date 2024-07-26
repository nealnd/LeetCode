public class Exercise58_1 {
    class Solution {
        public int lengthOfLastWord(String s) {
            String[] str = s.split(" ");
            return str[str.length - 1].length();
        }
    }
 
    public static void main(String[] args) {
        Exercise58_1 exercise=new Exercise58_1();
        Solution solution=exercise.new Solution();

        String s = "   fly me   to   the moon  ";
        System.out.println(solution.lengthOfLastWord(s));
        
        }
    }

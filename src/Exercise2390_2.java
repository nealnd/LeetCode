public class Exercise2390_2 {
    class Solution {
        public String removeStars(String s) {
            char[] ch = s.toCharArray();
            int i = 0, j = 0;
            for (; j < ch.length; j++) {
                if (ch[j] == '*')
                    i--;
                else {
                    ch[i++] = ch[j];

                }
            }
          
            return new String(ch).substring(0, i);
        }
    }
    
    public static void main(String[] args) {
        Exercise2390_2 exercise = new Exercise2390_2();
        Solution solution = exercise.new Solution();
        String s = "leet**cod*e";
        System.out.println(solution.removeStars(s));
    }
}

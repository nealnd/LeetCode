public class Exercise67 {
    class Solution {
        public String addBinary(String a, String b) {
            StringBuilder c = new StringBuilder();
            int sum = 0;
            int i = a.length() - 1, j = b.length() - 1;
            while (i >= 0 || j >= 0||sum==1) {
                if (i >= 0)
                    sum += a.charAt(i) - '0';//it is important
                if (j >= 0)
                    sum += b.charAt(j) - '0';
                c.append(sum % 2);
                sum = sum / 2;
                i--;
                j--;
            }
        
            //c.append(sum);
            return c.reverse().toString();
        }
    }

    public static void main(String[] args) {
        Exercise67 exercise = new Exercise67();
        Solution solution = exercise.new Solution();
        String a = "1010";
        String b = "1011";
        System.out.println(solution.addBinary(a, b));
    }
}

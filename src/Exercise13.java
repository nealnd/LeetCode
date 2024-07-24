import java.util.HashMap;
import java.util.Map;
import java.util.Stack;

public class Exercise13 {
    class Solution {
        public int romanToInt(String s) {
            Map<Character, Integer> map = new HashMap<>();
            map.put('I', 1);
            map.put('V', 5);
            map.put('X', 10);
            map.put('L', 50);
            map.put('C', 100);
            map.put('D', 500);
            map.put('M', 1000);
            int sum = 0;
            int i = 0;
            if (s.length() == 1)
                return map.get(s.charAt(0));
            if (s.length() > 1) {

                while (i < s.length()) {
                    if (i < s.length() - 1 && map.get(s.charAt(i)) < map.get(s.charAt(i + 1))) {
                        sum -= map.get(s.charAt(i));

                    } else {
                        sum += map.get(s.charAt(i));

                    }
                    i = i + 1;

                }

            }
            return sum;

        }

    }

    public static void main(String[] args) {
        Exercise13 exercise = new Exercise13();
        Solution solution = exercise.new Solution();

        String x = "MDCXCV";
        System.out.println(solution.romanToInt(x));

    }

}

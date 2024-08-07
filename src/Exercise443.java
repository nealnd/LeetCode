public class Exercise443 {
    class Solution {
        public int compress(char[] chars) {
            int i = 0, j = 0;
            int pt = 0;
            while (j < chars.length) {
                if (chars[j] == chars[i])
                    j++;
                else {
                    if (1 < j - i) {
                        String s = Integer.toString(j - i);
                        for (int k = 0; k < s.length(); k++) {

                            chars[++pt] = s.charAt(k);
                        }

                        chars[++pt] = chars[j];
                        // pt = i + 2;

                    } else {
                        chars[++pt] = chars[j];
                    }
                    i = j;

                }

            }

            if (j - i > 1) {
                String s = Integer.toString(j - i);
                for (int k = 0; k < s.length(); k++) {

                    chars[++pt] = s.charAt(k);
                }

            }
            pt++;
            return pt;
        }
    }

    public static void main(String[] args) {
        Exercise443 exercise = new Exercise443();
        Solution solution = exercise.new Solution();
        char[] chars = new char[] { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g',
                'g', 'a', 'b', 'c' };
        System.out.println(solution.compress(chars));
        for (char item : chars)
            System.out.println(item);
    }
}

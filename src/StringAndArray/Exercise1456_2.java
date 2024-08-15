package StringAndArray;
public class Exercise1456_2 {
    class Solution {
        public int maxVowels(String s, int k) {
            int[] vowels = new int[] { 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1,0,0,0,0,0 };
            int max_vow = 0;
            for (int i = 0, cur_vow = 0; i < s.length(); ++i) {
                cur_vow += vowels[s.charAt(i) - 'a'];
                if (i >= k)
                    cur_vow -= vowels[s.charAt(i - k) - 'a'];
                max_vow = Math.max(max_vow, cur_vow);
            }
            return max_vow;

        }
    }
    public static void main(String[] args) {
        Exercise1456_2 exercise = new Exercise1456_2();
        Solution solution = exercise.new Solution();
        String s = "rhythms";
        System.out.println(solution.maxVowels(s, 3));

    }
}

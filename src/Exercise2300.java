import java.util.Arrays;
public class Exercise2300 {
    class Solution {
        public int[] successfulPairs(int[] spells, int[] potions, long success) {

            int[] ans = new int[spells.length];
            Arrays.sort(potions);
            for (int i = 0; i < spells.length; i++) {
                int lo = 0, hi = potions.length - 1;
                while (lo <= hi) {
                    int mid = lo + (hi - lo) / 2;
                    if ((long) spells[i] * potions[mid] < success)
                        lo = mid + 1;
                    else if ((long) spells[i] * potions[mid] >= success)
                        hi = mid - 1;
                    }
                    ans[i] = potions.length - lo;
                }
                return ans;
                   
            }
           
        }


    public static void main(String[] args) {
        Exercise2300 exercise = new Exercise2300();
        Solution solution = exercise.new Solution();
        int[] spells = new int[] { 5,1,3 };
        int[] potions = new int[] { 1,2,3,4,5 };
        for (int i = 0; i < spells.length; i++) {
            System.out.println(solution.successfulPairs(spells, potions, 7)[i]);
        }
    }
}

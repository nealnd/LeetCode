import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class Exercise735 {
    class Solution {
        public int[] asteroidCollision(int[] asteroids) {
            ArrayList<Integer> temp = new ArrayList<>();
            for (int item : asteroids)
                temp.add(item);
            int i = temp.size()-2;
            int j = temp.size() - 1;
            while (i >= 0) {

                if (j<temp.size()&&temp.get(i) > 0 && temp.get(j) < 0) {
                    if (Math.abs(temp.get(i)) > Math.abs(temp.get(j))) {
                        temp.remove(j);

                    } else if (Math.abs(temp.get(i)) < Math.abs(temp.get(j))) {
                        temp.remove(i);
                    } else {
                        temp.remove(j);
                        temp.remove(i);
                    }

                }
                
                else {
                    i--;
                    j--;
                }

            }

            int[] ans = new int[temp.size()];
            for (int k = 0; k < temp.size(); k++) {
                ans[k] = temp.get(k);
            }
            return ans;
        }
    }

    public static void main(String[] args) {
        Exercise735 exercise = new Exercise735();
        Solution solution = exercise.new Solution();
        int[] nums = new int[] { -2,2,-1,-2 };
        int[] ans = solution.asteroidCollision(nums);
        for (int item : ans)
            System.out.println(item);
    }
}

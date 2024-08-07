
import java.util.HashMap;
public class Exercise1679_2 {
    class Solution {
        public int maxOperations(int[] nums, int k) {
            HashMap<Integer, Integer> map = new HashMap<>();
            int count = 0;
            for (int i = 0; i < nums.length; i++) {
                //to check if that k-nums[i] present and had some value left or already paired
                if (map.containsKey(k - nums[i]) && map.get(k - nums[i]) > 0) {
                    count++;
                    map.put(k - nums[i], map.get(k - nums[i]) - 1);
                } else {
                    //getOrDefault is easy way it directly checks if value is 0 returns 0 where I added 1
                    //and if some value is present then it return that value "similar to map.get(i)" and I added 1 on it 
                    map.put(nums[i], map.getOrDefault(nums[i], 0) + 1);
                }
            }
            return count;
        }
    }
    public static void main(String[] args) {
        Exercise1679_2 exercise = new Exercise1679_2();
        Solution solution = exercise.new Solution();
        int[] nums = new int[] { 3, 1, 3, 4, 3 };
        System.out.println(solution.maxOperations(nums, 6));
    }
}

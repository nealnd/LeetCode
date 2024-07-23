import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Exercise15_2 {
    class Solution {
        public List<List<Integer>> threeSum(int[] nums) {
            List<List<Integer>> ans = new ArrayList<>();
            Arrays.sort(nums);

            int lo, mid, hi;
            hi = nums.length - 1;

            for (lo = 0; lo < nums.length; lo++) {
                if (lo > 0 && nums[lo] == nums[lo - 1]) {
                    continue;
                }
                mid = lo + 1;
                while (mid < hi) {
                    int sum = nums[lo] + nums[mid] + nums[hi];
                    if (sum > 0)
                        hi--;
                    else if (sum < 0)
                        mid++;
                    else {

                        ans.add(Arrays.asList(nums[lo], nums[mid], nums[hi]));
                        mid++;
                        while (nums[mid] == nums[mid - 1] && mid < hi) {
                            mid++;
                        }
                    }
                }
            }

            return ans;
        }
    }

    public static void main(String[] args) {
        Exercise15_2 exercise = new Exercise15_2();
        Solution solution = exercise.new Solution();

        int nums[] = { -4, -2, -2, -2, 0, 1, 2, 2, 2, 3, 3, 4, 4, 6, 6 };
        List<List<Integer>> result = solution.threeSum(nums);
        for (List<Integer> triplet : result) {
            System.out.println(triplet);
        }

    }
}

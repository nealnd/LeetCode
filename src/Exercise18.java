import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Exercise18 {
    class Solution {
        public List<List<Integer>> fourSum(int[] nums, int target) {
            List<List<Integer>> ans = new ArrayList<>();
            Arrays.sort(nums);
            int lo, mid1, mid2, hi;
            for (lo = 0; lo < nums.length; lo++) {
                if (lo > 0 && nums[lo] == nums[lo - 1])
                    continue;
              
                for (mid1 = lo + 1; mid1 < nums.length-2 && (nums[lo] + nums[mid1]) <= target / 2; mid1++) {
                    mid2 = mid1 + 1;
                    if (mid1 > lo+1 && nums[mid1] == nums[mid1 - 1])
                        continue;
                        hi = nums.length - 1;
                    while (mid2 < hi && mid2 < nums.length - 1) {
                        long cmp =(long) target - nums[lo] - nums[mid1] - nums[mid2] - nums[hi];
                        if (cmp < 0)
                            hi--;
                        else if (cmp > 0) {
                            mid2++;
                        } else {
                            ans.add(Arrays.asList(nums[lo], nums[mid1], nums[mid2], nums[hi]));
                            mid2++;
                            while (mid2 < nums.length - 1 && nums[mid2] == nums[mid2 - 1])
                                mid2++;

                        }
                    }

                }

            }

            return ans;

        }
    }
    public static void main(String[] args) {
        Exercise18 exercise = new Exercise18();
        Solution solution = exercise.new Solution();

        int nums[] = {-1000000000,-1000000000,1000000000,-1000000000,-1000000000};
        List<List<Integer>> result = solution.fourSum(nums,294967296);
        for (List<Integer> triplet : result) {
            System.out.println(triplet);
        }

    }
    
}

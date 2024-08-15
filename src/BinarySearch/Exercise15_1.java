package BinarySearch;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Exercise15_1 {
    class Solution {
        public List<List<Integer>> threeSum(int[] nums) {
            List<List<Integer>> ans = new ArrayList<>();
            Arrays.sort(nums);

            int fst;// the first one
            int sec;// the second one
            int lo, mid, hi;

            for (int i = 0; i < nums.length; i++) {
                if (i > 0 && nums[i] == nums[i - 1]) {
                    continue;
                }
                fst = nums[i];
                for (int j = i + 1; j < nums.length - 1 && nums[j] <= -fst; j++) {
                    sec = nums[j];
                    lo = j + 1;
                    hi = nums.length - 1;
                    while (lo <= hi) {
                        mid = lo + (hi - lo) / 2;
                        if (-(fst + sec) < nums[mid])
                            hi = mid - 1;
                        else if (-(fst + sec) > nums[mid])
                            lo = mid + 1;
                        else {
                            ans.add(Arrays.asList(fst, sec, nums[mid]));
                            break;
                        }

                    }
                    while (nums[j + 1] == nums[j] && j < nums.length - 2)
                        j++;

                }
            }
            return ans;
        }
    }

    public static void main(String[] args) {
        Exercise15_1 exercise = new Exercise15_1();
        Solution solution = exercise.new Solution();

        int nums[] = { -4, -2, -2, -2, 0, 1, 2, 2, 2, 3, 3, 4, 4, 6, 6 };
        List<List<Integer>> result = solution.threeSum(nums);
        for (List<Integer> triplet : result) {
            System.out.println(triplet);
        }

    }
}

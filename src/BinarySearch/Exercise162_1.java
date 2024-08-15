package BinarySearch;
public class Exercise162_1 {
    class Solution {
        public int findPeakElement(int[] nums) {
            int lo = 0, hi = nums.length - 1;
            if (lo == hi)
                return 0;
            if (nums[lo] > nums[lo + 1])
                return lo;
            if (nums[hi] > nums[hi - 1])
                return hi;
            return findPeakElement(lo, hi, nums,0);
        }

        private int findPeakElement(int lo, int hi, int nums[], int ans) {
            if (hi - lo < 2)
                return 0;
            int mid = lo + (hi - lo) / 2;
            
            if (mid>=1&&nums[mid] > nums[mid - 1] && nums[mid]>nums[mid + 1])
                return mid;
            else {
                ans = findPeakElement(lo, mid, nums, ans);
                if(ans==0)
                ans = findPeakElement(mid, hi, nums, ans);
            }
            return ans;

        }
    }
    public static void main(String[] args) {
        Exercise162_1 exercise = new Exercise162_1();
        Solution solution = exercise.new Solution();

        int[] nums = new int[] { 1,2,1,3,5,6,4};
        System.out.println(solution.findPeakElement(nums));
    }
}

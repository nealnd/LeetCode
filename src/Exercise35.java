public class Exercise35 {
    class Solution {
        public int searchInsert(int[] nums, int target) {

            int i = 0, j = nums.length - 1;
            while (i <= j) {
                int mid = i + (j - i) / 2;
                if (nums[mid] < target){
                    i=mid+1;
                }
                else if (nums[mid] > target) {
                    j=mid-1;
                    continue;

                }
                else
                    return mid;
            }
            return i;
        }
    }

    public static void main(String[] args) {
        Exercise35 exercise = new Exercise35();
        Solution solution = exercise.new Solution();

        int[] nums = { 1, 3, 5, 6 };
        System.out.println(solution.searchInsert(nums, 5));
    }
}

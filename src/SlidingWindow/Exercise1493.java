package SlidingWindow;
public class Exercise1493 {
    class Solution {
        public int longestSubarray(int[] nums) {
            
            int left = 0, right = 0;
            int count = 1;
            int max=0;
            while (right<nums.length) {
                if(nums[right]==0)
                    count--;
                
                if (count < 0) {
                    max = Math.max(max, right - left-1);
                    if (nums[left] == 0)
                        count++;
                    left++;
                }
                right++;
            }
            max = Math.max(max, right - left-1);
            return max;
        }
    }
}

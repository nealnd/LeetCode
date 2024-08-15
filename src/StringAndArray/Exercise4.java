package StringAndArray;
import java.util.ArrayList;

public class Exercise4 {
    class Solution {
        public double findMedianSortedArrays(int[] nums1, int[] nums2) {
            int i = 0, j = 0;
            int k = 0;
            int[] ans = new int[nums1.length + nums2.length];
            while (i < nums1.length && j < nums2.length) {
                if (nums1[i] <= nums2[j]) {
                    ans[k] = nums1[i];
                    i++;
                    k++;
                } else {
                    ans[k] = nums2[j];
                    j++;
                    k++;
                }
            }
            while (i < nums1.length && j == nums2.length) {
                ans[k] = nums1[i];
                i++;
                k++;
            }
            while (i == nums1.length && j < nums2.length) {
                ans[k] = nums2[j];
                j++;
                k++;
            }
            if (ans.length % 2 == 1)
                return ans[ans.length / 2];
            else
                return (double) (ans[ans.length / 2] + ans[ans.length / 2 - 1]) / 2.0;
        }
    }

        public static void main(String[] args) {
            Exercise4 exercise = new Exercise4();
            Solution solution = exercise.new Solution();
            int[] nums1 = { 1, 1 };
            int[] nums2 = { 1, 2 };
            System.out.println(solution.findMedianSortedArrays(nums1, nums2));
        }
}

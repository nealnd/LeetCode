package HeapAndPriorityQueue;


import java.util.ArrayList;
import java.util.Comparator;
import java.util.Iterator;
import java.util.TreeSet;

public class Exerccise2542 {
    class Solution {
        public long maxScore(int[] nums1, int[] nums2, int k) {
            ArrayList<int[]> a = new ArrayList<>();
      
            for (int i = 0; i < nums1.length; i++) {
                a.add(new int[] { nums2[0], nums1[0] });
            }

            a.sort(new Comparator<int[]>() {
                public int compare(int[] nums1, int[] nums2) {
                    if (nums1[0] < nums2[0])
                        return -1;
                    else if (nums1[0] > nums2[0])
                        return 1;
                    else
                        return 0;
                }
            });


            int hi = nums1.length - k;
            for (int i = 0; i <= nums1.length - k; i++) {
                int temp1 = a.get(i)[0];
                int temp2 = a.get(i)[1];


            
                }
            }

        }
        
       


    }
}

package HeapAndPriorityQueue;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Iterator;
import java.util.PriorityQueue;
import java.util.TreeSet;

public class Exercise2542 {
    class Solution {
        public long maxScore(int[] speed, int[] efficiency, int k) {
            int n = speed.length;
            int[][] ess = new int[n][2];
            for (int i = 0; i < n; ++i)
                ess[i] = new int[] { efficiency[i], speed[i] };
            Arrays.sort(ess, (a, b) -> b[0] - a[0]);
            PriorityQueue<Integer> pq = new PriorityQueue<>(k, (a, b) -> a - b);
            long res = 0, sumS = 0;
            for (int[] es : ess) {
                pq.add(es[1]);
                sumS = (sumS + es[1]);
                if (pq.size() > k)
                    sumS -= pq.poll();
                if (pq.size() == k)
                    res = Math.max(res, (sumS * es[0]));
            }
            return res;
        }
    }
        

    

    public static void main(String[] args) {
        Exercise2542 exercise = new Exercise2542();
        Solution solution = exercise.new Solution();
        int[] nums1 = new int[] { 1, 3, 3, 2 };
        int[] nums2 = new int[] { 2, 1, 3, 4 };

        System.out.println(solution.maxScore(nums1, nums2, 3));
    }

}

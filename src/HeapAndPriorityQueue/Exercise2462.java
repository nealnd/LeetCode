package HeapAndPriorityQueue;

import java.util.PriorityQueue;

public class Exercise2462 {
    class Solution {
        public long totalCost(int[] costs, int k, int candidates) {
            int lo = 0, hi = costs.length - 1;
            long sum = 0;
            PriorityQueue<Integer> pq_lo = new PriorityQueue<>(candidates);
            PriorityQueue<Integer> pq_hi = new PriorityQueue<>(candidates);

            while (k > 0 && lo < hi) {
                if (pq_lo.size() < candidates) {
                    pq_lo.add(costs[lo++]);
                }
                if (pq_hi.size() < candidates) {
                    pq_hi.add(costs[hi--]);
                }
                if (pq_lo.size() == candidates && pq_hi.size() == candidates) {
                    sum += (pq_lo.peek() > pq_hi.peek() ? pq_hi.poll() : pq_lo.poll());
                    k--;
                }

            }
            while (k > 0 && lo >= hi) {
                if (lo == hi) {
                    pq_lo.add(costs[lo++]);
                }
                if(pq_lo.size()>0&&pq_hi.size()>0)
                    sum += (pq_lo.peek() > pq_hi.peek() ? pq_hi.poll() : pq_lo.poll());
                else if (pq_lo.size() > 0) {
                    sum += pq_lo.poll();
                }
                else{
                    sum += pq_hi.poll();
                }
                k--;

            }
            return sum;

        }
    }

    public static void main(String[] args) {
        Exercise2462 exercise = new Exercise2462();
        Solution solution = exercise.new Solution();
        int[] nums1 = new int[] {57,33,26,76,14,67,24,90,72,37,30 };
        int k = 11;
        int candidates = 2;

        System.out.println(solution.totalCost(nums1, k, candidates));
    }

}

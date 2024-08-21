package HeapAndPriorityQueue;

import java.util.PriorityQueue;

public class Exercise2336_1 {
    class SmallestInfiniteSet {
        int cur;
        PriorityQueue<Integer> pq;

        public SmallestInfiniteSet() {
            cur = 1;
            pq = new PriorityQueue<>();

        }

        public int popSmallest() {
            if (!pq.isEmpty()) {
                return pq.poll();
            }
            return cur++;

        }

        public void addBack(int num) {
            if (num < cur && !pq.contains(num))//here use contains, the performance is not good
                pq.add(num);
        }
    }

    public static void main(String[] args) {
        Exercise2336_1 exercise = new Exercise2336_1();
        SmallestInfiniteSet smallestInfiniteSet = exercise.new SmallestInfiniteSet();
        smallestInfiniteSet.addBack(2);
        System.out.println(smallestInfiniteSet.popSmallest());
        System.out.println(smallestInfiniteSet.popSmallest());
        System.out.println(smallestInfiniteSet.popSmallest());
        smallestInfiniteSet.addBack(1);
        System.out.println(smallestInfiniteSet.popSmallest());
        System.out.println(smallestInfiniteSet.popSmallest());
        System.out.println(smallestInfiniteSet.popSmallest());
    }
}

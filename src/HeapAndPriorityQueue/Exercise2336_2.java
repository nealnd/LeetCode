package HeapAndPriorityQueue;

import java.util.TreeSet;

public class Exercise2336_2 {
    class SmallestInfiniteSet {

        TreeSet<Integer> addedBackSet;
        int curMinTracker;

        public SmallestInfiniteSet() {
            this.addedBackSet = new TreeSet<>();
            this.curMinTracker = 1;
        }

        public int popSmallest() {
            if (!addedBackSet.isEmpty()) {
                int smallestValue = addedBackSet.first();
                addedBackSet.remove(smallestValue);
                return smallestValue;
            }
            return this.curMinTracker++;
        }

        public void addBack(int num) {
            if (num < this.curMinTracker) {
                addedBackSet.add(num);
            }
        }
    }

    public static void main(String[] args) {
        Exercise2336_2 exercise = new Exercise2336_2();
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

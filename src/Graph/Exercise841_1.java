package Graph;

import java.util.Queue;
import java.util.List;
import java.util.LinkedList;

public class Exercise841_1 {
    class Solution {
        public boolean canVisitAllRooms(List<List<Integer>> rooms) {

            boolean[] db = new boolean[rooms.size()];
            Queue<Integer> queue = new LinkedList<>();
            queue.offer(0);
            canVisitAllRooms(queue, db, rooms);
            for (boolean item : db) {
                if (item == false)
                    return false;
            }
            return true;

        }

        private void canVisitAllRooms(Queue<Integer> queue, boolean[] db, List<List<Integer>> rooms) {
            if (queue.isEmpty())
                return;
            int index = queue.poll();
            db[index] = true;
            for (int item : rooms.get(index)) {
                if (db[item] == false)
                    queue.offer(item);

            }
            canVisitAllRooms(queue, db, rooms);

        }
    }

    public static void main(String[] args) {
        Exercise841_1 exercise = new Exercise841_1();
        Solution solution = exercise.new Solution();
        List<List<Integer>> rooms = new LinkedList<>();

        LinkedList<Integer> room0 = new LinkedList<>();
        LinkedList<Integer> room1 = new LinkedList<>();
        LinkedList<Integer> room2 = new LinkedList<>();
        LinkedList<Integer> room3 = new LinkedList<>();
        room0.add(1);
        room1.add(2);
        room2.add(3);
        rooms.add(room0);
        rooms.add(room1);
        rooms.add(room2);
        rooms.add(room3);
        System.out.println(solution.canVisitAllRooms(rooms));
        

}
}

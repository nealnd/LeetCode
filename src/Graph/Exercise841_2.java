package Graph;

import java.util.List;

import java.util.LinkedList;

import java.util.HashSet;
public class Exercise841_2 {
    class Solution {
        public boolean canVisitAllRooms(List<List<Integer>> rooms) {
            HashSet<Integer> visited = new HashSet<>();
            canVisitAllRooms(visited, rooms, 0);

            return visited.size() == rooms.size();
        }

        private void canVisitAllRooms(HashSet<Integer> visited, List<List<Integer>> rooms, int index) {
            visited.add(index);
            for (int item : rooms.get(index))
                if (!visited.contains(item))
                    canVisitAllRooms(visited, rooms, item);

        }
    }
    
    public static void main(String[] args) {
            Exercise841_2 exercise = new Exercise841_2();
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

package StackAndQueue;
import java.util.LinkedList;
import java.util.Queue;

public class Exercise649 {
    class Solution {
        public String predictPartyVictory(String senate) {
          int n=senate.length();
            Queue<Integer> ra = new LinkedList<>();
            Queue<Integer> di = new LinkedList<>();
            for (int i = 0; i < senate.length(); i++) {
                if (senate.charAt(i) == 'R')
                    ra.offer(i);
                else
                    di.offer(i);
            }
            while (!ra.isEmpty() && !di.isEmpty()) {
                if (ra.peek() < di.peek())
                    ra.offer(n++);
                else
                    di.offer(n++);
                ra.poll();
                di.poll();
            }
            return ra.isEmpty() ? new String("Dire") : new String("Radiant");
        }
    }
    public static void main(String[] args) {
        Exercise649 exercise = new Exercise649();
        Solution solution = exercise.new Solution();
        String senate = "DRRDRDRDRDDRDRDR";
        System.out.println(solution.predictPartyVictory(senate));
    }
}

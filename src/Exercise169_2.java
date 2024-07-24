

public class Exercise169_2 {
        class Solution {
        public int majorityElement(int[] nums) {
            int count = 0;
            int candidate = 0;
            
            for (int num : nums) {
                if (count == 0) {
                    candidate = num;
                }
                
                if (num == candidate) {
                    count++;
                } else {
                    count--;
                }
            }
            
            return candidate;
        }
    }
        public static void main(String[] args) {
        Exercise169_2 exercise = new Exercise169_2();
        Solution solution = exercise.new Solution();

        int nums[] = { 1, 1, 2, 1, 2, 2, 2 };
        System.out.println(solution.majorityElement(nums));
      

    }
}

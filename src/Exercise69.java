public class Exercise69 {
    class Solution {
        public int mySqrt(int x) {
            int lo = 1, hi = x;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (mid  > x/mid)//avoid mid*mid>maxint
                    hi = mid - 1;
                else if (mid < x/mid)
                    lo = mid + 1;
                else
                    return mid;
            }
            return hi;

        }
    }

    public static void main(String[] args) {
        Exercise69 exercise = new Exercise69();
        Solution solution = exercise.new Solution();
        System.out.println(solution.mySqrt(8));
    }

}
